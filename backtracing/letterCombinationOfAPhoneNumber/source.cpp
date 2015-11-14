/*
Problem:
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.


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
    vector<string> letterCombinations(string digits) {
        string arr[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> dict;
        dict.assign(arr, arr+8); 
        vector<string> vec;
                                
        letterCombine(digits, dict, 0, vec, "");
        return vec;
    }
    void letterCombine(string digits, vector<string> dict, int index, vector<string> & result, string str){
        if(str.length() == digits.length()){
            result.push_back(str);
            return ;
        }
        if(index >= digits.length()) return;
        int curr = digits[index] - '0';
        if(curr <= 1 || curr >9 ) return;
        string matchLetter = dict[curr-2];
        for(int i = 0; i < matchLetter.length(); i++){
            str += matchLetter[i];
            letterCombine(digits, dict, index+1, result, str);
            str = str.substr(0, str.length() - 1);
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
    string arr[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> vec;
    vec.assign(arr, arr+8);
    vector<string > v2 = sl->letterCombinations("23");
    printVec(v2);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
