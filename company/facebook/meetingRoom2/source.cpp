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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){ return a.start < b.start; });
        int rooms = 1;
        vector<int> endTimes;
        endTimes.push_back(intervals[0].end);
        for(int i = 1; i< intervals.size(); i++){
            sort(endTimes.begin(), endTimes.end());
            if(intervals[i].start < endTimes[0] ){
                endTimes.push_back(intervals[i].end);
            }else
                endTimes[0] = intervals[i].end;
        }
        return endTimes.size();
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {1,0,2,2};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+4);
    vec2.assign(arr2, arr2+18);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
    /* char arr[ROW][COL] = {{'1'}};
       vector<vector<char> > vec;
       vec.resize(ROW);
       for(int i = 0; i < ROW; i++ ){
       vec[i].assign(arr[i], arr[i]+COL);
       }*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
