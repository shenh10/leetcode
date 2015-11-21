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
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return;
        int start_pos = 0, flag = 0;
        for(int i = 0; i < nums.size(); i++){
            if(flag && nums[start_pos] != 0) {
                flag = 0;
            }
            if(!flag){
                if(nums[i] != 0) continue;
                flag = 1; start_pos = i;
            }else{
                if(nums[i] != 0){
                    nums[start_pos] = nums[i];
                    nums[i] = 0;
                    start_pos ++;
                }else
                    continue;
            }
        }
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
   /* int arr[] = {1,0,2,2};
    int arr2[] = {4,2,6,2,3,5,1};
    vector<int> vec, vec2;
    vec.assign(arr, arr+4);
    vec2.assign(arr2, arr2+7);*/
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
     char arr[ROW][COL] = {{'1'}};
     vector<vector<char> > vec;
     vec.resize(ROW);
     for(int i = 0; i < ROW; i++ ){
        vec[i].assign(arr[i], arr[i]+COL);
     }
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
