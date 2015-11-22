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
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
    public:
        string addBinary(string a, string b) {
            if(a.length()==0 || b.length() == 0) return a+b;
            string s;
            s.resize(max(a.length(), b.length()) + 1, '0');
            int step = 0;
            if(a.length()>= b.length() ) {
                string t = a;
                a = b;
                b = t;
            }
            int j = b.length() - 1;
            for(int i =  a.length() - 1; i >= 0; i--, j--){
                int cur = s[j+1]-'0';
                int before = s[j] - '0';
                cur += (a[i]-'0') + (b[j]-'0') + step*2 ;
                before += cur / 2;
                cur %= 2;
                step = before / 2;
                before %=2;
                s[j+1] = cur + '0';
                s[j] = before + '0';

            }
            while(j >= 0 || step != 0){
                if(j < 0 && step != 0){
                    s[0] = ( s[0]- '0'+ step ) + '0';
                    step = 0;
                }else{
                    int  cur =  s[j+1] - '0' + ( b[j] - '0' ) + step;
                    step = cur/2;
                    cur = cur%2;
                    s[j+1] = cur + '0';
                    j--;
                }
            }
            int k = 0;
            while(k < s.length()){
                if(s[k] == '0') k++;
                else break;
            }
            return k == s.length()? "0": s.substr(k, s.length());
        }
};
#define ROW 4
#define COL 5
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {5,5,5,5,5,11,11,11,11,15};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+10);
    vec2.assign(arr2, arr2+18);
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
