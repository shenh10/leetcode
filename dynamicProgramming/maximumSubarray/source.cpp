/*
Problem:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.


Solution:
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
using namespace std;
template <typename T>
void printVec(vector<T> vec){
    cout<<"[";
    for (int i = 0; i< vec.size(); i++){
        cout<< vec[i]<<" ";

    }

    cout<<"]"<<endl;
}
template<typename T, int N> struct vector_wrapper {
    vector_wrapper(T (&a)[N]) {
        std::copy(a, a + N, std::back_inserter(v));
    }

    std::vector<T> v;
};

template <typename T>
void print2DVec(vector<vector<T> > vec){
    cout<<"[";
    for (int i = 0; i< vec.size(); i++){
        printVec(vec[i]);
    }
    cout<<"]"<<endl;
}

class Solution {
    public:
     int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        int len = nums.size();
        dp.resize(len);
        if( nums.empty() ) return 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i< len; i ++){
            if(i == 0) dp[i] = nums[i];
            else
             dp[i] = nums[i] + dp[i-1];
        }
        printVec(dp);
        int minSum = INT_MAX, maxSum = dp[0]; 
        for(int i = 1; i< len; i ++){
            minSum = min(minSum, dp[i-1]);
            maxSum = max(max(dp[i] - minSum, maxSum), dp[i] );
        }     
        return maxSum;
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();/*
   int arr[ ROW ][ COL ] = {{0,0,1},{1,1,0},{0,0,0}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);
      cout<< sl->uniquePathsWithObstacles(vec);*/
    int arr[] = {-1,-2,3};
    vector<int> vec;
    vec.assign(arr, arr+3);
    cout << sl-> maxSubArray(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
