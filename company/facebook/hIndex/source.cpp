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
        int hIndex(vector<int>& citations) {
            const auto n = citations.size();
            vector<int> count(n + 1, 0);
            for (const auto& x : citations) {
                // Put all x >= n in the same bucket.
                if (x >= n) {
                    ++count[n];
                } else {
                    ++count[x];
                }
            }

            int h = 0;
            for (int i = n; i >= 0; --i) {
                h += count[i];
                if (h >= i) {
                    return i;
                }
            }
            return h;
        }
};
#define ROW 4
#define COL 5
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {10,3,2,5,7,8};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+6);
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
    cout << sl->hIndex(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
