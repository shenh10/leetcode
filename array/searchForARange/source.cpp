/*
Problem:
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
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

class Solution {
    public:
    vector<int> searchRange(vector<int>& vec, int target) {
            int left = 0, right = vec.size()-1;
            int mid = (left + right)/2;
            vector<int> returnVec;
            while(mid != left){
                if(target == vec[mid]) {
                    int ln = mid, rn = mid;
                    while( ln >= 0 && vec[ln] == target ) ln --;
                    ln++;
                    while(rn <= vec.size() && vec[rn] == target ) rn ++;
                    rn--;
                    returnVec.push_back(ln);
                    returnVec.push_back(rn);
                    return returnVec;
                }
                else if(target < vec[mid]){
                    right = mid;
                } 
                else{
                    left = mid;
                } 
                mid = (left + right)/2;
            }
            if( vec[mid] == target || vec[right] == target){
                if(vec[mid] == target)
                     returnVec.push_back(mid);
                if( vec[right] == target)
                    returnVec.push_back(right);
                if( returnVec.size() == 1 )
                    returnVec.push_back(returnVec.back());
                return returnVec;
            }
            returnVec.push_back(-1);
            returnVec.push_back(-1);
            return returnVec;
        }
};
#define ROW 3
#define COL 4
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    vector<vector<int> > vec(ROW, vector<int>(COL));
    for(int i = 0 ; i< ROW; i++) 
        vec[i].assign(arr[i],arr[i]+COL);
    print2DVec(vec);*/
    int arr[] = {0,0,0,1,2,3};

    vector<int> vec;
    vec.assign(arr, arr+6);
    vector<int> rv = sl->searchRange(vec, 0);
    printVec(rv);
   // cout<<(bl == true? 1 :0);
    return 0;
}
