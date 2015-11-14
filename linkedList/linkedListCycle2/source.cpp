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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if(!head) return NULL;
            ListNode* fast = head, *slow = head, *restart = head;
            bool beginFlag = false;
            while(fast && slow){

                if(fast == slow && beginFlag){
                    break;
                }

                slow = slow->next;
                if(! fast->next) return NULL;
                fast = fast -> next -> next;
                beginFlag = true;
            }
            if(!fast ) return NULL;
            while(restart!= slow){
                restart = restart ->next;
                slow = slow ->next;
            }
            return restart;
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

int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {  1  };
    //int arr[] = {1,2};
    vector<int> vec;
    vec.assign(arr, arr+2);
    ListNode *list = arrayToList(vec);
    /*  ListNode *ptr = list;
        while(ptr->next){
        ptr = ptr->next;
        }
        ptr->next = list;
        */ListNode* node = sl->detectCycle(list);
    if(!node) cout<<-1;
    else cout<< node->val;
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
