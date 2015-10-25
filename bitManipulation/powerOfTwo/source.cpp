/*
Problem:
Given an integer, write a function to determine if it is a power of two.
Solution:
O(n) complexity:
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
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
    bool isPowerOfTwo(int n) {
        int bits = 1;
        if(n <= 0) return false;
        while(n !=  0){
            if(n == 1) return true;
            if( (n >> 1) << 1 == n){
                n = n>> 1;
                
            }else
                return false;
        }
        return true;
    }
 };
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {0, 1, 3};
    vector<int> vec;
    vec.assign(arr, arr+3);
    cout<< sl->isPowerOfTwo(16);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
