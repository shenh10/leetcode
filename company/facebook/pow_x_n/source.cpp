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
        double myPow(double x, int n) {
            if( n >= 0 )
                return countPow(x,n);
            else
                return 1.0/countPow(x,-n);
        }
        double countPow(double x,int n){
            double base = x;
            int dynamic_n = n;
            int k = 1;
            double product = 1;
            if(n <= 0) return 1;
            if(n == 1) return x;
            while( dynamic_n >1){
                base = base * base;
                k = k * 2;
                dynamic_n /= 2;
            }
            base = base* myPow(x, n - k);
            return base;
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
    cout << sl->myPow(8.26, 300);
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
