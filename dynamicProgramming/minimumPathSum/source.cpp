/*
Problem:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.


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
     int minPathSum(vector<vector<int> >& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp;
        dp.resize(m*n);
        for(int i = 0; i< m ; i++){
            for(int j = 0; j< n; j++){
                if(i == 0 && j!= 0) dp[j] = dp[j-1] + grid[0][j];
                else if(j == 0 && i!=0 ) dp[i*n] = dp[(i-1)*n] + grid[i][0];
                else dp[i*n+j] = grid[i][j];    
            }
        }
        for(int i = 1; i< m; i++){
            for(int j = 1; j< n; j++){
            dp[i*n+j] += min(dp[(i-1)*n+j], dp[i*n+j-1]);   
        }
    } 
        return dp[m*n-1];
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
   int arr[ ROW ][ COL ] = {{7,8,1},{3,5,9},{1,2,4}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);
      cout<< sl->minPathSum(vec);
   /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
    vecvector<int> vec;
    vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
