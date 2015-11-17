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
#include <deque>
#include <utility>
#include <tuple>
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
        bool isPalindrome(string s) {
            if(s.length() == 0) return true;
            int i = 0, j = s.length() - 1;
            while(i <= j){
                while( i <= j && !isAlphanumeric(s[i])) i++;
                while( i <= j && !isAlphanumeric(s[j])) j--;
                if(i >= j){
                    return true;
                }
                if(lower(s[i]) == lower(s[j]) ) {
                    i++;
                    j--;
                }else
                    return false;
            }
            return true;
        }
        char lower(char a){
            if(a >= 'A' && a<='Z')
                return a-'A'+'a';
            else
                return a;
        }
        bool isAlphanumeric(char a){
            return (a >='a' && a <= 'z') || (a >='A' && a <= 'Z') || (a >='0' && a <= '9');
        }
};
#define ROW 4
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[ ROW ][ COL ] = {{INT_MAX, -1, 0, INT_MAX},{INT_MAX, INT_MAX, INT_MAX, -1},{INT_MAX, -1, INT_MAX, -1},{0, -1, INT_MAX, INT_MAX}};
    vector<vector<int> > vec(ROW, vector<int>(COL));
    for(int i = 0 ; i< ROW; i++) 
        vec[i].assign(arr[i],arr[i]+COL);
    print2DVec(vec);/*
                       int arr[] = {1,0,2,2};
                       int arr2[] = {4,2,6,2,3,5,1};
                       vector<int> vec, vec2;
                       vec.assign(arr, arr+4);
                       vec2.assign(arr2, arr2+7);*/
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
