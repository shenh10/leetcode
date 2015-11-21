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
   string multiply(string num1, string num2) {
        int len1 = num1.length(),  len2 = num2.length();
        string result;
        result.resize(len1 + len2,'0' );
        int step = 0;
        for(int i = len1-1; i >=0; i--){
            for(int j = len2 - 1; j >= 0; j--){
                int s = charToNumber(num1[i]) * charToNumber(num2[j]) + step*10;
                int end = charToNumber(result[i+j+1]);
                int cur = charToNumber(result[i+j]);
                end += s%10;
                cur += s/10 + end /10;
                end %= 10; 
                step = cur/10;
                cur %= 10;
                result[i+j+1] = numToChar(end);
                result[i+j] = numToChar(cur);
            
        }
        result[0] = numToChar( charToNumber(result[0]) + step );
        int subpos = 0;
        for(int i = 0; i < len1+len2; i++){
            if(result[i] == '0') {
                subpos++;
            }else
                break;
        }
        if(subpos > len1 + len2 -1) return result.substr(len1+len2 -1);
        else
            return result.substr(subpos ,len1+len2);
    }
    int charToNumber(char c){
        return c - '0';
    }
    char numToChar(int c){
        return c+ '0';
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
    cout << sl-> multiply("99","99");
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
