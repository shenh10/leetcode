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
        bool exist(vector<vector<char> >& board, string word) {

            vector<vector<int> > mark;
            int len = board.size();
            mark.resize(len);
            for(int i = 0; i< len; i++){
                mark[i].resize(board[i].size());
            }

            for(int j = 0; j < len; j++){
                for(int k = 0; k < board[j].size(); k++){
                    if( dfs_v(board, mark, word, 0, j,k) )
                        return true;
                }
            }
            return false;

        }

        bool dfs_v(vector<vector<char> > &board, vector<vector<int> > &visited, string word, int target_char , int j , int k){
            if( j >= board.size() || j < 0 || k >= board[0].size() || k < 0 || visited[j][k] ||word[target_char] != board[j][k] ) return false;
            if(target_char == word.length() - 1){
                return true;
            }
            bool sub = false;
            visited[j][k]=1;
            sub = dfs_v(board, visited, word, target_char+1 , j+1, k) || dfs_v(board, visited, word, target_char+1 , j-1, k) || dfs_v(board, visited, word, target_char+1 , j, k+1) || dfs_v(board, visited, word, target_char+1 , j, k-1);

            visited[j][k]=0;
            return sub;

        }
};
#define ROW 3
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    char arr[ ROW ][ COL ] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char> > vec(ROW, vector<char>(COL));
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
    cout << sl->exist(vec, "ABCB");
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
