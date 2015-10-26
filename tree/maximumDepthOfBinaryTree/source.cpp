/*
Problem:
Solution:
O(n) complexity:
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
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
        void depthFirstSearch(){
            TreeNode* ptr = root;
            vector<TreeNode*> mystack;
            while(ptr != NULL || !mystack.empty()){
                while(ptr != NULL){
                    mystack.push_back(ptr);
                    ptr = ptr->left;
                }
                    ptr = mystack.back();
                    mystack.pop_back();
                    cout<< ptr->val <<" ";
                    ptr = ptr->right;
            }
        }


};

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL) return 0;
            if(root -> left == NULL && root-> right == NULL) return 1;
            int leftDepth = 0,rightDepth = 0;
            TreeNode* ptr = root;
            if(root -> left !=NULL ) leftDepth = maxDepth(root -> left);
            if(root -> right !=NULL ) rightDepth = maxDepth(root -> right);
            return 1+ max(leftDepth, rightDepth);
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
    vector<int> vec;
    vec.assign(arr, arr+7);
    BinarySearchTree bsTree(vec);
    bsTree.depthFirstSearch();
    cout<<endl;
    cout<< sl->maxDepth(bsTree.root);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
