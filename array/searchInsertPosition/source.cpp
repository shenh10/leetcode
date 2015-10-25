/*
Problem:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
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
        int searchInsert(vector<int>& vec, int target) {
            int left = 0, right = vec.size()-1;
            int mid = (left + right)/2;
            vector<int> returnVec;
            while(mid != left){
                if(target == vec[mid]) {
                    return mid;
                }
                else if(target < vec[mid]){
                    right = mid;
                } 
                else{
                    left = mid;
                } 
                mid = (left + right)/2;
            }
            if(vec[mid] >= target)
                return mid;
            if( vec[right] == target)
                return right;
            if(vec[right] < target)
                return right + 1;
            if(vec[right]> target && vec[mid]< target)
                return mid+1;
            return 0;
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
    int arr[] = {1,3,5,6};

    vector<int> vec;
    vec.assign(arr, arr+4);
    cout<<  sl->searchInsert(vec, 0);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
