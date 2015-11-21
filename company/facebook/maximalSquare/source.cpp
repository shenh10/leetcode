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
        struct unit_{
            int width, height;
        };
        int maximalSquare(vector<vector<char> >& matrix) {
            if(matrix.empty()) return 0;
            vector<vector<int> > size;
            vector<vector<unit_> > side;
            side.resize(matrix.size());
            size.resize(matrix.size());

            for(int i = 0; i < matrix.size(); i++){
                side[i].resize(matrix[0].size());
                size[i].resize(matrix[0].size());
            }
            for(int i = matrix.size()-1 ; i >= 0; i--){
                for(int j = matrix[0].size() - 1; j >= 0; j--){
                    side[i][j].height =  matrix[i][j] == '1' ? ( i+1 >= matrix.size() ? 1: side[i+1][j].height +1): 0; 
                    side[i][j].width =  matrix[i][j] == '1' ? ( j+1 >= matrix[0].size() ? 1: side[i][j+1].width +1): 0; 
                }
            }
            int max_side_global = 0;
            for(int i = matrix.size()-1 ; i >= 0; i--){
                for(int j = matrix[0].size() - 1; j >= 0; j--){
                    int min_side = min(side[i][j].width, side[i][j].height);
                    size[i][j] =  matrix[i][j] == '1' ? ( i+1 >= matrix.size() ? 1: min( min_side,size[i+1][j+1]+1 ) ): 0; 
                    max_side_global = max(max_side_global, size[i][j]);
                }
            }
            return max_side_global * max_side_global;

        }
};
#define ROW 4
#define COL 5
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[] = {1,0,2,2};
      int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
      vector<int> vec, vec2;
      vec.assign(arr, arr+4);
      vec2.assign(arr2, arr2+18);
    // vector<string > v2 = sl->letterCombinations("23");
    // printVec(v2);*/
    //vector<int> out = sl->productExceptSelf(vec);
    char arr[ROW][COL] = {{'1','0', '1', '0', '0'},{ '1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'},{'1', '0', '0', '1', '0'}};
    vector<vector<char> > vec;
    vec.resize(ROW);
    for(int i = 0; i < ROW; i++ ){
        vec[i].assign(arr[i], arr[i]+COL);
    }
    cout << sl->maximalSquare(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
