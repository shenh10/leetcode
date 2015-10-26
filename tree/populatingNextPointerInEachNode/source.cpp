/*
Problem:
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.



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
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class BinarySearchTree{
    public:
        TreeLinkNode *root;
        BinarySearchTree(){}
        BinarySearchTree(vector<int> vec){
            for(int i = 0; i< vec.size(); i++){
                if(i == 0){
                    root = new TreeLinkNode(vec[i]);
                    continue;
                }
                TreeLinkNode* node = new TreeLinkNode(vec[i]);
                TreeLinkNode* ptr = root;
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
        vector<int> preOrderDFS( TreeLinkNode* root ){
            vector<TreeLinkNode*> myqueue;
            vector<int> vec;
            TreeLinkNode* ptr = NULL;
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
        vector<int> midOrderDFS( TreeLinkNode* root){
            TreeLinkNode* ptr = root;
            vector<TreeLinkNode*> mystack;
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
        vector<int> postOrderDFS(TreeLinkNode* root){
            vector<TreeLinkNode*> mystack;
            vector<int> vec;
            TreeLinkNode* ptr = root, *right = NULL;
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
        vector<vector<int> > levelOrder(TreeLinkNode* root) {
            vector<std::pair<int, TreeLinkNode*> > myqueue;
            vector<vector<int> > vec;
            vector<int> subvec;
            TreeLinkNode* treeHead = root;
            int level = 0, last_level = 0;;
            if(root == NULL) return vec;
            myqueue.push_back(std::pair<int , TreeLinkNode*>(0,root));
            while(! myqueue.empty() ){
                std::pair<int, TreeLinkNode*> front_pair = myqueue.front();
                level = front_pair.first;
                TreeLinkNode* ptr = front_pair.second;
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
                    myqueue.push_back(std::pair<int, TreeLinkNode*>(level + 1,ptr->left));
                if(ptr -> right )
                    myqueue.push_back(std::pair<int, TreeLinkNode*>(level + 1, ptr->right));

            } 
            vec.push_back(subvec);
            return vec;   
        }
        bool isPowerOfTwo(int n) {
            int bits = 1;
            if(n <= 0) return false;
            while(n !=  0){
                if(n == 1) return true;
                if( (n >> 1) << 1 == n){
                    n = n>> 1;

                }else
                    return false;
            }
            return true;
        }

        TreeLinkNode* buildNormalTree(vector<int> vec){
            TreeLinkNode* root = NULL;
            TreeLinkNode* ptr = NULL;
            vector<TreeLinkNode*> myqueue;
            int level = log2(vec.size()) + 1;
            int current_level = 0;
            int tree_id = 0;
            bool isLeft = true;
            while(tree_id < vec.size()){
                if(tree_id == 0){
                    root = new TreeLinkNode(vec[0]);
                    myqueue.push_back(root);
                    tree_id++;
                    current_level++;
                    continue;
                }
                int current_row_head = pow(2,current_level )-1;
                int parent_row_head = pow(2,current_level -1 )-1;
                int parent_id = parent_row_head + (tree_id - current_row_head)/2;  
                if(vec[tree_id] != INT_MIN){
                    TreeLinkNode* node = new TreeLinkNode(vec[tree_id]);
                    myqueue.push_back(node);
                    if(isLeft){
                        myqueue[parent_id]->left = node;
                        isLeft = false;
                    }
                    else{
                        myqueue[parent_id]->right = node;
                        isLeft = true;
                    }
                    tree_id++;
                }else{
                    TreeLinkNode* node = NULL;
                    myqueue.push_back(node);
                    isLeft = isLeft? false:true;
                    tree_id++;
                }
                if(pow(2, current_level) == (tree_id - current_row_head))
                    current_level++;
            }
            return root;
        }


};

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL) return;
            subConnect(root, NULL);
        }
        void subConnect(TreeLinkNode* pre, TreeLinkNode* post){
            if(pre -> left){
                subConnect(pre->left, pre->right);
                pre->left->next = pre->right;
                if(post == NULL){

                    subConnect(pre->right, NULL);
                    pre->right->next = NULL;
                }else
                {
                    subConnect(pre->right, post->left);
                    pre->right->next = post->left;
                }
            }else{
                pre->next = post;

            }
        }
        void printPointer(TreeLinkNode* root){
            if(root == NULL) return;
            TreeLinkNode* ptr = root, *pre = ptr;
            while(pre!= NULL){
                cout<< ptr->val<<"->";
                while(ptr->next){
                    ptr = ptr->next;
                    cout<<ptr->val<<"->";
                }
                cout<<"NULL"<<endl;
                if(pre->left ) ptr = pre->left;
                else break;
                pre = ptr;
            }

        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = { 0, 1 ,2 ,5, 9,8,3 };
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
    BinarySearchTree bsTree;
    TreeLinkNode* root = bsTree.buildNormalTree(vec);
    // TreeLinkNode* root2 = bsTree.buildNormalTree(vec);
    vector<vector<int> > levelOrderVec = bsTree.levelOrder(root);
    print2DVec(levelOrderVec);
    sl->connect(root);
    sl->printPointer(root);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
