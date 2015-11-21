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
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> output;
            if(nums.empty()) return output;
            output.resize(nums.size(), 1);
            for(int i = 1; i < nums.size(); i++){
                output[i] = output[i-1]*nums[i-1];  
            }
            int right_product = 1;
            for(int i = nums.size() - 2; i >=0; i--){
                right_product *= nums[i+1];
                output[i] *= right_product;  
            }
            return output;
        }
};
#define ROW 3
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {1,0,2,2};
    int arr2[] = {4,2,6,2,3,5,1};
    vector<int> vec, vec2;
    vec.assign(arr, arr+4);
    vec2.assign(arr2, arr2+7);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    vector<int> out = sl->productExceptSelf(vec);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
