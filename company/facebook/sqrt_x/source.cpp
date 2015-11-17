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
    int mySqrt(int x) {
        if(x <= 0) return 0;
        return partition(1, x, x);
    }
    int partition(int start, int end, int target){
        int mid = start + (end - start)/2;
        if(mid == start) return end <= target/end? end:start;
        if(mid < target/mid )
            return partition(mid, end, target);
        else if(mid > target/mid )
            return partition(start, mid-1, target);
        else
            return mid;
    }
};
int main( int argc, char* argv[]){
       return 0;
}
