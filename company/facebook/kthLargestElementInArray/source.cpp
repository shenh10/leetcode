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
     int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        int left = 0, right = nums.size() - 1;
        while(1){
            int pivot_id = left + floor(rand()/INT_MAX*(right-left));
            int new_pivot_id = quickSort(nums, left, right, pivot_id);
            if(new_pivot_id == nums.size() - k )
                return nums[new_pivot_id];
            if(new_pivot_id < nums.size() - k){
                left = new_pivot_id + 1;
            }
            if(new_pivot_id > nums.size() - k)
                right = new_pivot_id - 1;
        }
    }
    int quickSort(vector<int> &nums, int left, int right, int pivot_id){
        if(left > right )
            return 0;
        if( left == right ) return left;
        int pivot_value = nums[pivot_id];
        nums[pivot_id] = nums[left];
        nums[left] = pivot_value;
        int i = left , j = right;
        while(i < j){
            while(j > i && nums[j] > pivot_value) j--;
            if( j > i) nums[i++] = nums[j];
            while(i < j && nums[i] < pivot_value) i++;
            if(i < j) nums[j--] = nums[i];
        }
        nums[i] = pivot_value;
        return i;
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
    cout << sl->findKthLargest(vec, 1);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
