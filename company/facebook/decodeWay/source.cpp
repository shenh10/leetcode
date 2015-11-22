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
class Solution {
    public:
        int numDecodings(string s) {
            if(s.empty()) return 0;
            if(s[0] == '0') return 0;
            if(s.length() == 1) return 1;
            vector<int> dp;
            dp.resize(s.length());
            if(s[0] == '0' || (s[0]!= '1' && s[0] != '2') && s[1] == '0') return 0;
            dp[0] = 1;
            if(s[0] == '1' && s[1]!='0' || s[0] == '2' && s[1]>'0' && s[1]<='6'  ) dp[1] = 2;
            else dp[1] = 1;
            for(int i = 2; i < s.length(); i++ ){
                if(s[i] == '0') {
                    if( s[i-1]!= '1' && s[i-1] != '2')
                        return 0;
                    dp[i] = dp[i-2];
                    continue;
                }
                if(s[i-1] > '2' ) dp[i] = dp[i-1];
                else{
                    if(s[i-1] == '1' ||  s[i-1] == '2' && s[i] <= '6') dp[i] = dp[i-2] + dp[i-1];
                    else dp[i] = dp[i-1];
                }
            }
            return dp[s.length() - 1];
        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = { 0, 1 ,2 , INT_MIN, INT_MIN,8,3 };
    //int arr[] = {1,2};
    vector<int> vec;
    vec.assign(arr, arr+7);
    /*  BinarySearchTree bsTree(vec);
        vector<int> preOrderVec = bsTree.preOrderDFS( bsTree.root);
        printVec(preOrderVec);
        vector<int> midOrderVec = bsTree.midOrderDFS( bsTree.root);
        printVec(midOrderVec);
        vector<int> postOrderVec = bsTree.postOrderDFS(bsTree.root);
        printVec(postOrderVec);*/
    // TreeNode* root2 = bsTree.buildNormalTree(vec);
    // vector<vector<int> > levelOrderVec = bsTree.levelOrder(root);
    // print2DVec(levelOrderVec);
    cout<<endl;

    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
