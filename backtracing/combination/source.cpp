/*
Problem:
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.



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
  vector<vector<int> > combine(int n, int k) {
       vector<vector<int> > vec;
        if(k > n) return vec;
        if(k <=0 || n<=0) return vec;
        vector<vector<int> > l1 = combine(n-1, k);
        vector<vector<int> > l2 = combine(n-1, k-1);
        for(int i = 0; i< l1.size(); i++)
            vec.push_back(l1[i]);
        for(int i = 0; i< l2.size(); i++){
            l2[i].push_back(n);
            vec.push_back(l2[i]);
        }
        if( l2.empty() && k == 1){
            vector<int> subvec;
            subvec.push_back(n);
            vec.push_back(subvec);
        }
        return vec;
    }
 };
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[ ROW ][ COL ] = {{7,8,1},{3,5,9},{1,2,4}};
    vector<vector<int> > vec(ROW, vector<int>(COL));
    for(int i = 0 ; i< ROW; i++) 
        vec[i].assign(arr[i],arr[i]+COL);
    print2DVec(vec);
    vector<vector<int> > v2 = sl->combine(4,2);
    print2DVec(v2);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
