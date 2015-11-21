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

class Solution {
    public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.empty()) return 0;
        vector<vector<int> > visited;
        visited.resize(grid.size());
        for(int i = 0; i < grid.size(); i++){
            visited[i].resize(grid[i].size());
        }
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                count += dfs(grid, visited, i, j);
            }
        }
        return count;
    }
    int dfs(vector<vector<char> > &grid, vector<vector<int> > &visited, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0  || visited[i][j]) return 0;
        visited[i][j] = 1;
        if(grid[i][j] == '0'){
            return 0;
        }
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
        return 1;
    }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
   /* int arr[] = {1,0,2,2};
    int arr2[] = {4,2,6,2,3,5,1};
    vector<int> vec, vec2;
    vec.assign(arr, arr+4);
    vec2.assign(arr2, arr2+7);*/
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
     char arr[ROW][COL] = {{'1'}};
     vector<vector<char> > vec;
     vec.resize(ROW);
     for(int i = 0; i < ROW; i++ ){
        vec[i].assign(arr[i], arr[i]+COL);
     }
    cout << sl-> numIslands(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
