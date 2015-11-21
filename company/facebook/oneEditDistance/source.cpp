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
        bool isOneEditDistance(string s, string t) {
            int len1 = s.length();
            int len2 = t.length();
            if( abs(len1-len2)>1) return false;
            if(len1 == 0 && len2 == 0) return false;
            if(len1 == 0 || len2 == 0) return true;
            bool flag = false;
            if(len1 == len2){
                int i = 0;
                while(i < len1 ){
                    if(s[i] != t[i]){
                        if(!flag)
                            flag = true;
                        else
                            return false;
                    }
                    i++;
                }
                return flag;

            }
            if(len1 < len2){
                int i = 0, j = 0;
                while(i< len1){
                    if(s[i] != t[j]){
                        if( !flag ){
                            flag = true;
                            j = i+1;
                            continue;
                        }else return false;
                    }
                    i++;
                    j++;
                }
                return true;
            }
            if(len1 > len2){
                int i = 0, j = 0;
                while(j < len2){
                    if(s[i] != t[j]){
                        if( !flag ){
                            flag = true;
                            i = j+1;
                            continue;
                        }else return false;
                    }
                    i++;
                    j++;
                }
                return true;
            }
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
    //vector<int> out = sl->productExceptSelf(vec);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
