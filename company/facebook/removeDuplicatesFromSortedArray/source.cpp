/*
Problem:
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).


Solution:
*/

#include "iostream"
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        cout<<"here";
        if(nums.empty()) return 0;
        int cur = nums[0];
        printVec(nums);
        int count = nums.size();
        vector<int>::iterator it;
        for(it = nums.begin() ; it < nums.end();  ){
            if(it + 2 < nums.end() && *(it+2) != cur ) { while(*it == cur ) it ++; cur = *it;}
            else if (it + 2 > nums.end() ) { printVec(nums); return nums.size();}
            else {
                it = it + 2;
                while(it < nums.end() &&*it == cur ){
                    nums.erase(it);
                }
            }
        }
        printVec(nums);
        return nums.size();
    }
};

int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {  1,2,2,2  };
    //int arr[] = {1,2};
    vector<int> vec;
    vec.assign(arr, arr+4);
    printVec(vec);
    sl->removeDuplicates(vec);
    /*  ListNode *ptr = list;
        while(ptr.next){
        ptr = ptr.next;
        }
        ptr.next = list;
        *///ListNode* node = sl.detectCycle(list);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
