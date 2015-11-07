/*
Problem:

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

class Solution {
    public:
string factorial(int maximum, int minimum){
     string a  = to_string(maximum);
     for(int i = maximum - 1 ; i >= minimum; i --){
        a = multiple(a, to_string(i));
    }    
    return a;

}
string multiple( string a, string b ){
    int lena = a.length();
    int lenb = b.length();
    vector<int> c ;
    c.resize(lena + lenb);
    for( int i = 0; i< lena; i ++ ){
        for(int j = 0; j < lenb ; j++){
             c[i+j] += (b[lenb -1 -j]-48) * (a[lena -1 - i] - 48);
             c[i+j+1] += c[i + j] /10;
             c[i+j] %= 10;
        }
    }
    for( int i = c.size() -1; i >=0 ; i-- ){
        if(c[i] == 0)
            c.pop_back();
        else
            break;
    }
    string s;
    for( int i = c.size() -1; i >=0 ; i-- ){
        s.append( to_string(c[i]) );
    }
    return s;
}
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {6, 5, 9, 7, 3, 4 , 3};
    vector<int> vec;
    vec.assign(arr, arr+7);
    //cout<<  sl->uniquePaths(100,100);
    cout << sl->factorial(100, 1);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
