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
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int  sumCandy = 0;
        vector<int> candy;
        candy.resize(ratings.size(),1);
        if(ratings.size() == 1) return 1;
        for(int i = 1; i < ratings.size(); i++){
          if(ratings[i] > ratings[i-1]){
                candy[i] = max(candy[i], candy[i-1]+1);
            }
        }
        for(int i = ratings.size() - 2; i >= 0; i--){
          if(ratings[i] > ratings[i+1]) candy[i] = max(candy[i], candy[i+1]+1);
        }
        for(int i = 0; i< candy.size(); i++){
            sumCandy += candy[i];
        }
        return sumCandy;
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
    int arr[] = {1,0,2,2};
    int arr2[] = {4,2,6,2,3,5,1};
    vector<int> vec, vec2;
    vec.assign(arr, arr+4);
    vec2.assign(arr2, arr2+7);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    cout << sl->candy(vec);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
