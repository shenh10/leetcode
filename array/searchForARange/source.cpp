/*
Problem:

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Solution: I adopted O(mlgn) approach, the better solution is O(n)
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
template <typename T>
void printVec(vector<T> vec){
    cout<<"[";
    for (int i = 0; i< vec.size(); i++){
        cout<< vec[i]<<" ";

    }
    
    cout<<"]"<<endl;
};
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

template <typename T>
void assignArrayTo2DVector( vector<vector<T> > & vec, T **arr , int row, int col){
    for( int i = 0; i < row; i ++){
        vector<T> subvec;
        for(int j = 0; j < col; j++){
            subvec.push_back(arr[i][j]);
        }
        vec.push_back(subvec);
    }
}
#define BASE 10
class Solution {
    public:
        bool searchMatrix(vector<vector<int> >& matrix, int target) {
            int len = matrix.size();
            if( len != 0 && (target < matrix[0][0] || target > matrix[len-1][matrix[len-1].size()-1]))
                return false;
            for(int i = 0; i< len; i ++){
                if( target > matrix[i][0] ) continue;
                if( target == matrix[i][0] ) return true;
                int index = i - 1;
                return searchLine(matrix[index], 0, matrix[index].size() -1,target);
            }
                return searchLine(matrix[len -1], 0, matrix[len -1].size() -1,target);
        }
        bool searchLine(vector<int> & vec ,int left, int right, int target){
            int mid = (left + right)/2;
            while(mid != left){
                if(target == vec[mid]) return true;
                else if(target < vec[mid]) return searchLine(vec, left, mid, target);
                else return searchLine(vec, mid, right,target);

            }
            if(target == vec[mid] || target == vec[right]) return true;
            return false;
        }
};
#define ROW 3
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    //int **arr = new int*[3];
   // vector<> = new {1,3,5,7};
    vector<vector<int> > vec(ROW, vector<int>(COL));
    for(int i = 0 ; i< ROW; i++) 
        vec[i].assign(arr[i],arr[i]+COL);
    //vec.push_back(vector<int>(begin(arr[0]), end(arr[0])));
    //vec.push_back(vector<int>(begin(arr[1]), end(arr[1])));
    print2DVec(vec);
    // vector<vector<int> > vec;
    // vec.push_back( vector<int>().assign(arr[0]));
    bool bl = sl->searchMatrix(vec, 50);
    cout<<(bl == true? 1 :0);
    return 0;
}
