/*
Problem:subsets
Given a set of distinct integers, nums, return all possible subsets.

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
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp, sum ;
        dp.resize(nums.size(), INT_MAX);
        sum.resize(nums.size(), 0);
        sum[0] = nums[0];
        if(sum[0]>=s) return 1;
        for(int i = 1; i < nums.size(); i++){
            sum[i]  = sum[i-1] + nums[i];
            if(nums[i]>= s) return 1;
            if(sum[i] < s) continue;
            if(sum[i-1]< s && sum[i]>=s) { 
                int step = 1;
                while(i >= step && sum[i] - sum[i-step] < s) step++;
                if(step > i) dp[i] = i+1;
                else
                    dp[i] = step ;
                continue;
            }
            int count = 0;
            dp[i] = dp[i-1];
            int step = dp[i];
            while (sum[i] - sum[i-step + 1] >= s) step --;
            dp[i] = step;
        }
        if(dp[nums.size() - 1] == INT_MAX) return 0;
        printVec(dp);
        return dp[nums.size() - 1];
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {1,0,2,2};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+4);
    vec2.assign(arr2, arr2+18);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
    /* char arr[ROW][COL] = {{'1'}};
     vector<vector<char> > vec;
     vec.resize(ROW);
     for(int i = 0; i < ROW; i++ ){
        vec[i].assign(arr[i], arr[i]+COL);
     }*/
    cout<< sl->minSubArrayLen(100, vec2);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
