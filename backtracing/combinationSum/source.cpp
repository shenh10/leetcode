/*
Problem:
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.


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
        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            vector<vector<int> > vec;
            sort(candidates.begin(), candidates.end());
            printVec(candidates);
            vector<int> subVec;
            combinationSumSub(candidates, target, 0, subVec, vec);
            return vec;

        }
        void combinationSumSub(vector<int>& candidates, int target, int start, vector<int> curr,vector<vector<int> > &vec ){
            if(target == 0){
                vec.push_back(curr);
                return;
            }
            if(target < 0){
                return;
            }
            for(int i = start; i < candidates.size(); i++){
                curr.push_back(candidates[i]);
                combinationSumSub(candidates, target - candidates[i], i, curr, vec);
                curr.pop_back();
            }
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
    int arr[] = {2,3,6,7};
    vector<int> vec;
    vec.assign(arr, arr+4);
    vector<vector<int> > v2 = sl->combinationSum(vec,7);
    print2DVec(v2);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
