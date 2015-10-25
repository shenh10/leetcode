/*
Problem:
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Solution:
O(n) complexity:
1) Hash map, value as key, 2 scan O(2*n) but used O(n) space
2) sum up (1...n) - sum(array) = missing number, satisfied
3) (Best) XOR, XOR(1...n) XOR XOR(array) = missing number
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
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
       int realxor = nums[0], expectedxor = 0; 
       for(int i = 1; i< nums.size()+1; i++)
            expectedxor ^= i;
        for(int i = 1; i< nums.size(); i++)
            realxor ^= nums[i];
       return expectedxor ^ realxor;
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
    cout<<  sl->missingNumber(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
