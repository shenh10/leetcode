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
    string countAndSay(int n) {
        int i = 1;
        string s = "1";
        while(i < n){
            i++;
            int count = 0, start = 0;
            string new_s = "";
            for(int j = 0; j< s.length(); j++){
                if(s[j] == s[start]) count ++;
                else{
                    new_s.append(1,char(count+'0'));
                    new_s.append(1,s[start]);
                    count = 1;
                    start = j;
                }
            }
            if(count > 0) new_s.append(1, char(count+'0'));
            new_s.append(1,s[start]);
            s = new_s;
        }
        return s;
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
