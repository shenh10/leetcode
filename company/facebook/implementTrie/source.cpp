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
#define ROW 4
#define COL 5
#define MAX_CHILDREN 26
class TrieNode {
public:
    int completed;
    TrieNode* childrens[MAX_CHILDREN];
    // Initialize your data structure here.
    TrieNode() {
        completed = 0;
        for(int i = 0; i< MAX_CHILDREN; i++){
            childrens[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        int i = 0;
        while( i < word.length()){
            if(ptr->childrens[word[i] - 'a'] == NULL){
                ptr->childrens[word[i]-'a'] = new TrieNode();
            }
            ptr = ptr->childrens[word[i] - 'a'];
            i++;
        }
        if(i == word.length()){
            ptr->completed = 1;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
        int i = 0;
        while( i < word.length()){
            if(ptr->childrens[word[i] - 'a'] == NULL){
                return false;
            }else{
                ptr = ptr->childrens[word[i] - 'a'];
            }
            i++;
        }
        return ptr->completed? true:false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        int i = 0;
        while( i < prefix.length()){
            if(ptr->childrens[prefix[i]-'a'] == NULL){
                return false;
            }else{
                ptr = ptr->childrens[prefix[i] - 'a'];
            }
            i++;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main( int argc, char* argv[]){
    Trie tree;
    tree.insert("a");
    cout<< tree.search("a")<<endl;
    cout<< tree.startsWith("a")<<endl;
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
    /*char arr[ROW][COL] = {{'1','0', '1', '0', '0'},{ '1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'},{'1', '0', '0', '1', '0'}};
      vector<vector<char> > vec;
      vec.resize(ROW);
      for(int i = 0; i < ROW; i++ ){
      vec[i].assign(arr[i], arr[i]+COL);
      }*/
    //   printVec(vec);
    // cout << sl->hIndex(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
