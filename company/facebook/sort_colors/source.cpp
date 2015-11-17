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
     void sortColors(vector<int>& nums) {
        printVec(nums);
        int left = 0, right = nums.size() - 1;
        if(nums.size() <= 1) return;
        for(int i = 0; i<= nums.size()-1 && i <=right; ){
            if(nums[i] == 0){
                int t = nums[i];
                nums[i] = nums[left];
                nums[left] = t;
                left++;
                i++;
            }else if(nums[i] == 2){
                int t = nums[i];
                nums[i] = nums[right];
                nums[right] = t;
                right--;
            }else i++;
        }
    }
};
int main( int argc, char* argv[]){
        Solution sl;
        int arr[] = {0,1,1,2,1,0,2,1,0};
       vector<int> vec;
        vec.assign(arr, arr+9);
        sl.sortColors(vec);
       return 0;
}
