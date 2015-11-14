/*
Problem:
min number of square to n

Solution:
dp[i] = min(dp[i] , dp[i - k *k])
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
  int numSquares(int n) {
     
     vector<int> dp;
    dp.resize(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n ; i++){
        for(int k = 1; k * k <= i; k++){
            dp[i] = min(dp[i - k*k]+1, dp[i]);
        }
    }
    printVec(dp);
    return dp[n]; 
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
    cout<< sl->numSquares(13);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
