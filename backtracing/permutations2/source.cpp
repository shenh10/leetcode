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
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > vec;
        vector<int> subVec;
        if(nums.empty()) {
            vec.push_back(subVec);
            return vec;
        }
sort(nums.begin(), nums.end());
        vector<int> hash_map;
        hash_map.resize(nums.size());
        buildPermutation(subVec, vec, nums, hash_map);
        
        return vec;
        
    }
    void buildPermutation(vector<int> subvec, vector<vector<int> >& results, vector<int> nums, vector<int> hash_map){
        if(subvec.size() == nums.size()){
            results.push_back(subvec);
            return;
        }
        for(int i = 0 ; i< nums.size(); ){
            if(hash_map[i] == 1) { i++; continue;}
            subvec.push_back(nums[i]);
            hash_map[i] = 1;
            buildPermutation(subvec, results, nums, hash_map);
            subvec.pop_back();
            hash_map[i] = 0;
            i++;
            while(nums[i] == nums[i-1]) i++;
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
    int arr[] = {1,2,2};
    vector<int> vec;
    vec.assign(arr, arr+3);
    vector<vector<int> > v2 = sl->permute(vec);
    print2DVec(v2);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
