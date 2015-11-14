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
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        if(nums.size() == 1) return true; 
        for(int i = 0; i < nums.size();){
            if(nums[i]>0){
                i = i + nums[i];
            }else{
                if(i==0)
                    return false;
                else if(i == nums.size() - 1)
                    return true;
                else{
                   int j = i - 1;
                   while(j > 0 && nums[j] <= i - j) j--;
                   if(j == 0)
                        return false;
                    else
                        i = j;
                }
            }
            
        }
        return true;
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
   /* string arr[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> vec;
    vec.assign(arr, arr+8);
    vector<string > v2 = sl->letterCombinations("23");
    printVec(v2);*/
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
