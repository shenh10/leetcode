/*
Problem:
Find the contiguous subarray within an array (containing at least one number) which has the largest product.




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
        int maxProduct(vector<int>& nums) {
            if(nums.empty()) return 0;
            int len = nums.size();
            int maxP = nums[0], minP = nums[0],p = nums[0];
            for( int i = 1 ; i < nums.size(); i++ ){
                int t = maxP ;
                maxP = max( max( t*nums[i], nums[i]), minP*nums[i]);
                minP = min(min(minP*nums[i], nums[i]), t*nums[i]);
                p = max(p, maxP);
            }
            return p;
        }
 };
#define ROW 3
#define COL 3
int main( int argc, char* argv[]){
    Solution* sl = new Solution();/*
   int arr[ ROW ][ COL ] = {{0,0,1},{1,1,0},{0,0,0}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);
      cout<< sl->uniquePathsWithObstacles(vec);*/
    int arr[] = {2,-5,-2,-4,3};
    vector<int> vec;
    vec.assign(arr, arr+5);
    cout << sl-> maxProduct(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
