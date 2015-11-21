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
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
    public:
        int strStr(string haystack, string needle) {
            int len1 = haystack.size(), len2 = needle.size();
            if(len1 < len2) return -1;
            if(len1 == 0) return 0;
            vector<int> table;
            table.resize(len2, -1);
            partialMatchTable(needle,table);
            int match_count = 0;
            int j = -1;
            for(int i = 0; i< len1;i++){
                while( j > -1 && haystack[i] != needle[j+1]){
                    j = table[j];
                }
                if(haystack[i] == needle[j+1])
                    j++;
                if(j == len2 - 1 ) return i - j;

            }
            return -1;
        }
        void partialMatchTable(string &needle, vector<int> &table){
            int k = -1;
            for(int i = 1; i < needle.length();i++ ){
                while(k > -1 && needle[k+1] != needle[i]){
                    k = table[k];
                }
                if( needle[ k + 1] == needle[i])
                    k ++;
                table[i] = k;
            }
            printVec(table);
        }
};
#define ROW 4
#define COL 5
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {2, 1};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+2);
    vec2.assign(arr2, arr2+18);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
    /*char arr[ROW][COL] = {{'1','0', '1', '0', '0'},{ '1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'},{'1', '0', '0', '1', '0'}};
      vector<vector<char> > vec;
      vec.resize(ROW);
      for(int i = 0; i < ROW; i++ ){
      vec[i].assign(arr[i], arr[i]+COL);
      }*/
    printVec(vec);
    cout << sl->strStr("ababcdefdcbcababcdsc","abcdabd");
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
