/*
Problem:

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
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int > dp;
        dp.resize(m*n);
        int rowFlag = false, colFlag = false;
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
             if( obstacleGrid[i][j] == 1 ){
                dp[i*n+j] = 0;
                if(i == 0) rowFlag = true;
                if(j == 0) colFlag = true;
             }
             else{
                    if(i==0 && rowFlag) dp[i*n+j] = 0;
                    else if(j==0 && colFlag) dp[i*n+j] = 0;
                    else
                    dp[i*n+j] = 1;
            }
        }
    }
        printVec(dp);
        if(obstacleGrid[0][0] == 1) return 0;
        if( m== 1 || n==1 ){
            if(m == 1){
                int i = 0;
                while(i<n){
                    if( obstacleGrid[0][i] ) return 0;
                    i++;
                }
                return 1;
            }
            if(n == 1){
                int i = 0;
                while(i<m){
                    if( obstacleGrid[i][0] ) return 0;
                    i++;
                }
                return 1;
            }

            
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1)
                    dp[i*n + j] = 0;
                else if (obstacleGrid[i-1][j] == 1)
                    dp[i*n+j] = dp[i*n+j-1];
                else if (obstacleGrid[i][j-1] == 1)
                    dp[i*n+j] = dp[(i-1)*n+j];
                else
                    dp[i*n+j] = dp[(i-1)*n+j] + dp[i*n+j-1];
                if(obstacleGrid[i][j] == 1) dp[i*n+j] = 0;

            }

        }    
        printVec(dp);
        return dp[m*n-1]; 
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
   int arr[ ROW ][ COL ] = {{0,0,1},{1,1,0},{0,0,0}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);
      cout<< sl->uniquePathsWithObstacles(vec);
   /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
    vecvector<int> vec;
    vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
