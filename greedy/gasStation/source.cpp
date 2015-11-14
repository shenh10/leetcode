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
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int start = 0;
            int total = 0;
            int sum = 0;
            for(int i = 0; i < gas.size(); i++){
                sum  += gas[i] - cost[i];
                if(sum < 0){
                    start = i+1;
                    sum = 0;
                }
                total += gas[i] - cost[i];
            }
            if(total < 0)
                return -1;
            else return start;
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
    int arr[] = {4,3,4,5,2,6,1};
    int arr2[] = {4,2,6,2,3,5,1};
    vector<int> vec, vec2;
    vec.assign(arr, arr+7);
    vec2.assign(arr2, arr2+7);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    cout << sl->canCompleteCircuit(vec, vec2);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
