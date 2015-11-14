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
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int next = INT_MIN, step = 0, cur = 0;
        for(int i = 0; i < nums.size();){
            if( cur >= nums.size()-1 ) return step;
            while(i  <= cur ){
                next = max(next, nums[i] + i);
                i++;
            }
            step++;
            cur = next;
        }
        return step;
    }
 };
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /* int arr[ ROW ][ COL ] = {{7,8,1},{3,5,9},{1,2,4}};
       vector<vector<int> > vec(ROW, vector<int>(COL));
       for(int i = 0 ; i< ROW; i++) 
       vec[i].assign(arr[i],arr[i]+COL);
       print2DVec(vec);*/
    int arr[] = {2,3,1,0,4,3,5,1,1,2,0,1,1,2};
   vector<int> vec;
    vec.assign(arr, arr+14);
   // vector<string > v2 = sl->letterCombinations("23");
   // printVec(v2);*/
    cout << sl->jump(vec);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
