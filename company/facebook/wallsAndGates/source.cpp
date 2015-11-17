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
        void wallsAndGates(vector<vector<int> >& rooms) {
            if(rooms.empty()) return;
            deque<pair<int, int> > myqueue;

            for(int i = 0; i < rooms.size(); i++){
                for(int j = 0; j < rooms[0].size();j++){
                    if(rooms[i][j]==0){
                        myqueue.push_back(make_pair(i,j));
                    }
                }
            }
            while(!myqueue.empty()){
                pair<int, int> d = myqueue.front();
                myqueue.pop_front();
                int i = d.first;
                int j = d.second;
                vector<pair<int, int> > list;
                list.push_back(make_pair(i+1, j));  
                list.push_back(make_pair(i, j+1));  
                list.push_back(make_pair(i-1, j));  
                list.push_back(make_pair(i, j-1));
                int k = 0, l = 0;
                for(int e = 0; e < list.size(); e++ ){
                    k = list[e].first;
                    l = list[e].second;
                    if(k < rooms.size() && k >=0 && l < rooms[0].size() && l >=0 && rooms[k][l] == INT_MAX){
                        rooms[k][l] = rooms[i][j] + 1;
                        myqueue.push_back(make_pair(k,l));
                    }
                }
            }
            print2DVec(rooms);
        }
};
#define ROW 4
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[ ROW ][ COL ] = {{INT_MAX, -1, 0, INT_MAX},{INT_MAX, INT_MAX, INT_MAX, -1},{INT_MAX, -1, INT_MAX, -1},{0, -1, INT_MAX, INT_MAX}};
    vector<vector<int> > vec(ROW, vector<int>(COL));
    for(int i = 0 ; i< ROW; i++) 
        vec[i].assign(arr[i],arr[i]+COL);
    print2DVec(vec);/*
                       int arr[] = {1,0,2,2};
                       int arr2[] = {4,2,6,2,3,5,1};
                       vector<int> vec, vec2;
                       vec.assign(arr, arr+4);
                       vec2.assign(arr2, arr2+7);*/
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    sl->wallsAndGates(vec);
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
