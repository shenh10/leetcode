/*
Problem:
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

Solution:
dp[i] = sum(dp[k] * dp[i - k -1])
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BinarySearchTree{
    public:
        TreeNode *root;
        BinarySearchTree(){}
        BinarySearchTree(vector<int> vec){
            for(int i = 0; i< vec.size(); i++){
                insertValue(root, vec[i]);
            }
        }
        void insertValue( TreeNode * root, int value ){
            if(root == NULL){
                root = new TreeNode(value);
                return;
            }
            TreeNode* node = new TreeNode(value);
            TreeNode* ptr = root;
            while(ptr != NULL){
                if( ptr-> val < value){
                    if( ptr -> right == NULL) {
                        ptr->right = node;
                        break;
                    }
                    else
                        ptr = ptr -> right;
                }else if(ptr->val > value){
                    if(ptr->left == NULL){
                        ptr->left = node;
                        break;
                    }else
                        ptr = ptr -> left;
                }
            }

        }
        vector<int> preOrderDFS( TreeNode* root ){
            vector<TreeNode*> mystack;
            vector<int> vec;
            TreeNode* ptr = NULL;
            if(root == NULL) return vec;
            mystack.push_back(root);
            while(! mystack.empty()){
                ptr = mystack.back();
                vec.push_back(ptr->val);
                mystack.pop_back();
                if(ptr -> right) mystack.push_back(ptr->right);
                if(ptr -> left) mystack.push_back(ptr->left);
            }
            return vec;
        }
}; 
class Solution {
    public:
        vector<TreeNode*> generateTrees(int n) {
            return generateTreeRecursive(1,n);  
        }
        vector<TreeNode*> generateTreeRecursive(int start, int stop){
            vector<TreeNode*> vec;
            if(start > stop){
                vec.push_back(NULL);
                return vec;
            }
            if(start == stop){
                TreeNode* newNode = new TreeNode(start);
                vec.push_back(newNode);
                return vec;
            }
            for(int i = start; i<=stop; i++){
                vector<TreeNode*> l = generateTreeRecursive(start, i-1);
                vector<TreeNode*> r = generateTreeRecursive(i+1, stop);
                for(int j = 0; j < l.size(); j++){
                    for(int k = 0; k < r.size(); k++){
                        TreeNode * newNode = new TreeNode(i);
                        newNode->left = l[j];
                        newNode -> right = r[k];
                        vec.push_back(newNode);
                    }
                }
            }
            return vec;
        }
};
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[ ROW ][ COL ] = {{7,8,1},{3,5,9},{1,2,4}};
    vector<vector<int> > vec(ROW, vector<int>(COL));
    for(int i = 0 ; i< ROW; i++) 
        vec[i].assign(arr[i],arr[i]+COL);
   // print2DVec(vec);
    vector<TreeNode*> vecTree = sl->generateTrees(4);
    BinarySearchTree bt;
    vector<int> vecInt;
    for(int i = 0; i < vecTree.size(); i++){
       vecInt = bt.preOrderDFS(vecTree[i]); 
       printVec(vecInt);
    }
    /* int arr[] = {{0,0,0},{0,1,0},{0,0,0}};
       vecvector<int> vec;
       vec.assign(arr, arr+7);*/
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
