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
      int uniquePaths(int m, int n) {
        vector<int > dp;
        dp.resize(m*n,1);
        for(int i = 1; i< m ; i ++){
            for(int j = 1; j < n; j++ ){
                dp[i*n + j] = dp[(i-1)*n+j] + dp[ i*n + j-1 ];
            }
        }
        return dp[m*n-1];
    }



};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {6, 5, 9, 7, 3, 4 , 3};
    vector<int> vec;
    vec.assign(arr, arr+7);
    cout<<  sl->uniquePaths(100,100);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
