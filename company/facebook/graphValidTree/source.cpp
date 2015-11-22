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
        struct Node{
            int parent = -1;
            vector<Node*> neighbors;
            Node(int x){
                parent = x;  
            } 
        };
        bool validTree(int n, vector<pair<int, int>>& edges) {
            if(n == 0) return false;
            if(n == 1 && edges.empty()) return true;
            if(edges.empty()) return false;
            Node* nodes[n];
            for(int i = 0; i < n; i++){
                nodes[i] = new Node(i); 
            }
            for(int i = 0; i < edges.size(); i++){
                nodes[edges[i].first]->neighbors.push_back(nodes[edges[i].second]);
                nodes[edges[i].second]->neighbors.push_back(nodes[edges[i].first]);
            }
            vector<int> mark;
            set<pair<int, int>> visited_set;
            mark.resize(n);
            int count = 0, marked_count = 0;
            bool result = true, not_isolate = false;
            result &= traveselGraph(mark,visited_set,nodes[count], marked_count);
            return result && marked_count == n;
        }
        bool traveselGraph(vector<int> &mark, set<pair<int, int>>& visited_set, Node* cur, int &count){
            if( mark[cur->parent] == 1 ) return false;
            bool flag = true;
            mark[cur->parent] = 1;
            count ++;
            set<pair<int, int>>::iterator m;
            for(int i = 0 ; i < cur->neighbors.size() ;i++){
                pair<int, int> edge_pair1 = make_pair(cur->neighbors[i]->parent, cur->parent);
                pair<int, int> edge_pair2 = make_pair(cur->parent,cur->neighbors[i]->parent);
                m = visited_set.find(edge_pair1);
                if(m == visited_set.end()){
                    visited_set.insert(edge_pair2);
                }else continue;
                flag &= traveselGraph(mark,visited_set, cur->neighbors[i], count);
            }
            return flag;
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
