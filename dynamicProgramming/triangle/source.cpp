/*
Problem:
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.


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
   int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.empty()) return 0;
        int m = triangle.size();
        int sum = 0;
        vector<vector<int> > dp;
        dp.resize(m);
        dp[0].resize(1);
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < m ; i++){
            dp[i].resize(i+1);
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            for(int j = 1; j < i  ; j++){
              dp[i][j] =min( dp[i-1][j-1] , dp[i-1][j])+ triangle[i][j];
            }
        }
        return rowMin(dp[m-1]);

        
    }
    int rowMin(vector<int> num){
            int minSum = INT_MAX;
            for(int i = 0; i< num.size(); i++){
                minSum= min(minSum, num[i]);
            }
            return minSum;
        }
      };
#define ROW 4
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
   int arr[ ROW ][ COL ] = {{2},{3,4},{6,5,7},{4,1,8,3}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+i+1);
      print2DVec(vec);/*
      cout<< sl->uniquePathsWithObstacles(vec);*/
   /* int arr[] = {2,-5,-2,-4,3};
    vector<int> vec;
    vec.assign(arr, arr+5);*/
    cout << sl-> minimumTotal(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
