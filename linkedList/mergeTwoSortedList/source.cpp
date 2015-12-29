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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* head = NULL;
            ListNode* ptr1 = l1, *ptr2 = l2, *ptr= NULL;
            while(ptr1 || ptr2){
                if(ptr1 && ptr2){
                    if(ptr1->val < ptr2->val){
                        if(!head) { head = ptr1; ptr = head; }
                        else {
                            ptr -> next = ptr1;
                            ptr = ptr1;

                        }
                        ptr1 = ptr1->next;
                    }else {
                        if(!head) { head = ptr2; ptr = head; }
                        else {
                            ptr -> next = ptr2;
                            ptr = ptr2;
                        }
                        ptr2 = ptr2->next;
                    }
                }
                if(ptr1 && !ptr2){
                    if(!head) { head = ptr1; ptr = head; }
                    else {
                        ptr -> next = ptr1;
                        ptr = ptr1;
                    }
                    ptr1 = ptr1->next;
                }
                if(! ptr1 && ptr2){
                    if(!head) { head = ptr2; ptr = head; }
                    else {
                        ptr -> next = ptr2;
                        ptr = ptr2;
                    }
                    ptr2 = ptr2->next;
                }
            }
            return head;
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
    if(!head) return;
    ListNode* ptr = head;
    while(ptr){
        cout<<ptr->val << "->";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {  1,2,3  };
    int arr2[] = {2,3,6};
    vector<int> vec,vec2;
    vec.assign(arr, arr+3);
    vec2.assign(arr2, arr2+3);
    ListNode *list1 = arrayToList(vec);
    ListNode *list2 = arrayToList(vec2);
    /*  ListNode *ptr = list;
        while(ptr->next){
        ptr = ptr->next;
        }
        ptr->next = list;
        */ListNode* node = sl->mergeTwoLists(list1,list2);
    printList(node);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
