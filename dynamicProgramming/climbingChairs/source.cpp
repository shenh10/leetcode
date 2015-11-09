/*
Problem:
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Solution:
dp[i] = dp[i-1]+ dp[i-2];
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
     int climbStairs(int n) {
        if( n <= 0 ) return 0;
        if( n == 1 ) return 1;
        int lastWay = 1, lastLastWay = 1;
        int way = 1;
        for(int i = 2; i <= n; i++){
            way = lastWay + lastLastWay;
            lastLastWay = lastWay;
            lastWay = way;
        }   
        return way;
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
    int arr[] = {2,-5,-2,-4,3};
    vector<int> vec;
    vec.assign(arr, arr+5);
    cout << sl-> climbStairs(3);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
