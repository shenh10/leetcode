/*
Problem:
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.


Solution: I used same approach as largestRectangle, which is O(n), while we can use binary search to reach O(logn)
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
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
     int findPeakElement(vector<int>& nums) {
        vector<int> mystack;
        for(int i = 0; i< nums.size(); i++){
            if(  mystack.empty() || nums[i]> nums[mystack.back()])
            {   
                 mystack.push_back(i);
                continue;
            }
            if( nums[i] < nums[mystack.back()])
                return mystack.back();
        }    
        return nums.size() -1;
    }
};
#define ROW 3
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {2,1};

    vector<int> vec;
    vec.assign(arr, arr+2);
    cout<<  sl->findPeakElement(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
