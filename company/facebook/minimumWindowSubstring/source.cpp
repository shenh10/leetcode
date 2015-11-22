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
        string minWindow(string s, string t) {
            map<char, int> current, expected;
            for(int i = 0; i< t.length(); i++){
                expected[t[i]]++;
            }
            int min_start = 0, start_ptr = 0, min_width = INT_MAX, count = 0;
            for(int i = 0; i< s.length(); i++){
                current[s[i]]++;
                if(current[s[i]] <= expected[s[i]]) count ++;
                if( count == t.length() ){
                    while ( expected[s[start_ptr]] == 0 || expected[s[start_ptr]] < current[s[start_ptr]] ) { 
                        current[s[start_ptr]] --;
                        start_ptr++;
                    }
                    if (min_width > i - start_ptr + 1){
                        min_width = i - start_ptr + 1;
                        min_start = start_ptr;
                    }
                }
            }
            if(min_width == INT_MAX) return "";
            return s.substr(min_start,  min_width);
        }
};
#define ROW 4
#define COL 5
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {5,5,5,5,5,11,11,11,11,15};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+10);
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
    //   printVec(vec);
    // cout << sl->hIndex(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
