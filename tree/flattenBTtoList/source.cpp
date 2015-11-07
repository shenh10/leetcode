/*
Problem:
Given a binary tree, flatten it to a linked list in-place.

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

        TreeNode* buildNormalTree(vector<int> vec){
            TreeNode* root = NULL;
            TreeNode* ptr = NULL;
            vector<TreeNode*> myqueue;
            int level = log2(vec.size()) + 1;
            int current_level = 0;
            int tree_id = 0;
            bool isLeft = true;
            while(tree_id < vec.size()){
                if(tree_id == 0){
                    root = new TreeNode(vec[0]);
                    myqueue.push_back(root);
                    tree_id++;
                    current_level++;
                    continue;
                }
                int current_row_head = pow(2,current_level )-1;
                int parent_row_head = pow(2,current_level -1 )-1;
                int parent_id = parent_row_head + (tree_id - current_row_head)/2;  
                if(vec[tree_id] != INT_MIN){
                    TreeNode* node = new TreeNode(vec[tree_id]);
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
                    TreeNode* node = NULL;
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
    void flatten( TreeNode* root ){
            vector<TreeNode*> mystack;
            TreeNode* head = NULL, *newListPtr = NULL;
            TreeNode* ptr = NULL;
            if(root == NULL) return ;
            mystack.push_back(root);
            while(! mystack.empty()){
                ptr = mystack.back();
                if(!head) {
                    head = ptr;
                    newListPtr = head;
                }
                else {
                    newListPtr->right = ptr;
                    newListPtr = ptr;
                }
                mystack.pop_back();
                if(ptr -> right) {
                    mystack.push_back(ptr->right);
                    ptr -> right = NULL;
                }
                if(ptr -> left) {
                    mystack.push_back(ptr->left);
                    ptr -> left = NULL;
                }
            }
            root = head;
        }

                void insertValue( TreeNode * &root, int value ){
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
                }else
                    return;
            }
        }

};
ListNode* arrayToList( vector<int> vec ){
    ListNode* head = NULL, *ptr = NULL;
    for(int i = 0; i < vec.size(); i++){
        if(head == NULL){
            head = new ListNode( vec[i] );
            ptr = head;
            continue;
        }
        ListNode* node = new ListNode(vec[i]);
        ptr->next = node;
        ptr = node;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* ptr = head;
    while(ptr != NULL){
        cout<< ptr-> val <<" ";
        ptr = ptr -> next;
    }
}
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = { 0, 1 ,2 ,5, 8,9 };
    //int arr[] = {1,2};
    vector<int> vec;
    vec.assign(arr, arr+6);
    /*  BinarySearchTree bsTree(vec);
        vector<int> preOrderVec = bsTree.preOrderDFS( bsTree.root);
        printVec(preOrderVec);
        vector<int> midOrderVec = bsTree.midOrderDFS( bsTree.root);
        printVec(midOrderVec);
        vector<int> postOrderVec = bsTree.postOrderDFS(bsTree.root);
        printVec(postOrderVec);*/
    BinarySearchTree bsTree;
    TreeNode* root = bsTree.buildNormalTree(vec);
    sl->flatten(root);
    // TreeNode* root2 = bsTree.buildNormalTree(vec);
    vector<vector<int> > levelOrderVec = bsTree.levelOrder(root);
    print2DVec(levelOrderVec);
    cout<<endl;

    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
