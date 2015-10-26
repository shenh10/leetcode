/*
Problem:
Given preorder and inorder traversal of a tree, construct the binary tree.
Solution:
*/

#include "iostream"
#include <vector>
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinarySearchTree{
    public:
        TreeNode *root;
        BinarySearchTree(vector<int> vec){
            for(int i = 0; i< vec.size(); i++){
                if(i == 0){
                    root = new TreeNode(vec[i]);
                    continue;
                }
                TreeNode* node = new TreeNode(vec[i]);
                TreeNode* ptr = root;
                while(ptr != NULL){
                    if( ptr-> val < vec[i]){
                        if( ptr -> right == NULL) {
                            ptr->right = node;
                            break;
                        }
                        else
                            ptr = ptr -> right;
                    }else if(ptr->val > vec[i]){
                        if(ptr->left == NULL){
                            ptr->left = node;
                            break;
                        }else
                            ptr = ptr -> left;
                    }
                }

            }
        }
        vector<int> preOrderDFS( TreeNode* root ){
            vector<TreeNode*> myqueue;
            vector<int> vec;
            TreeNode* ptr = NULL;
            if(root == NULL) return vec;
            myqueue.push_back(root);
            while(! myqueue.empty()){
                ptr = myqueue.front();
                vec.push_back(ptr->val);
                if(ptr -> left) myqueue.push_back(ptr->left);
                if(ptr -> right) myqueue.push_back(ptr->right);
                myqueue.erase(myqueue.begin());
            }
            return vec;
        }
        vector<int> midOrderDFS( TreeNode* root){
            TreeNode* ptr = root;
            vector<TreeNode*> mystack;
            vector<int> vec;
            while(ptr != NULL || !mystack.empty()){
                while(ptr != NULL){
                    mystack.push_back(ptr);
                    ptr = ptr->left;
                }
                ptr = mystack.back();
                mystack.pop_back();
                vec.push_back(ptr->val);
                ptr = ptr->right;
            }
            return vec;
        }
        vector<int> postOrderDFS(TreeNode* root){
            vector<TreeNode*> mystack;
            vector<int> vec;
            TreeNode* ptr = root, *right = NULL;
            while(ptr != NULL || ! mystack.empty()){
                while(ptr != NULL){
                    if(ptr->right)
                        mystack.push_back(ptr->right); 
                    mystack.push_back(ptr);
                    ptr = ptr->left;
                }
                ptr = mystack.back();
                mystack.pop_back();
                if(ptr -> right && mystack.back() == ptr->right){
                    right = mystack.back();
                    mystack.pop_back();
                    mystack.push_back(ptr);
                    ptr = ptr->right;
                }else{
                    vec.push_back(ptr-> val);
                    ptr = NULL;
                }
            }
            return vec; 
        }


};

class Solution {
    public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<std::pair<int, TreeNode*> > myqueue;
        vector<vector<int> > vec;
        vector<int> subvec;
        TreeNode* treeHead = root;
        int level = 0, last_level = 0;;
        if(root == NULL) return vec;
        myqueue.push_back(std::pair<int , TreeNode*>(0,root));
        while(! myqueue.empty() ){
            std::pair<int, TreeNode*> front_pair = myqueue.front();
            level = front_pair.first;
            TreeNode* ptr = front_pair.second;
            if(level == last_level){
               subvec.push_back(ptr->val);
            }else{
                vector<int> newVec;
                subvec.swap(newVec);
                vec.push_back(newVec);
                subvec.push_back(ptr->val);
                last_level = level;
            }
            myqueue.erase(myqueue.begin());
            if(ptr -> left )
                myqueue.push_back(std::pair<int, TreeNode*>(level + 1,ptr->left));
            if(ptr -> right )
                myqueue.push_back(std::pair<int, TreeNode*>(level + 1, ptr->right));

        } 
        vec.push_back(subvec);
        return vec;   
    }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = { 0, 43 ,2 , 1,7,8,3 };
    //int arr[] = {1,2};
    vector<int> vec;
    vec.assign(arr, arr+7);
    BinarySearchTree bsTree(vec);
    vector<int> preOrderVec = bsTree.preOrderDFS( bsTree.root);
    printVec(preOrderVec);
    vector<int> midOrderVec = bsTree.midOrderDFS( bsTree.root);
    printVec(midOrderVec);
    vector<int> postOrderVec = bsTree.postOrderDFS(bsTree.root);
    printVec(postOrderVec);
    cout<<endl;
    vector<vector<int> > vec2= sl->levelOrder(bsTree.root);
    print2DVec(vec2);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
