/*
Problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Solution:
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
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
    int maxProfit(vector<int>& prices) {
        int min1 = INT_MAX, max2 = INT_MIN;
        int profit1 = 0, profit2 = 0, profit = 0;
        if(prices.size() <= 1) return 0;
        if(prices.size() == 2) return max(prices[1]- prices[0], 0);
        vector<int> profits;
        profits.resize(prices.size());
        for(int j = prices.size() -2 ; j >=0; j--){
                max2 = max(prices[j+1 ], max2);
                profit2 = max(profit2, max2 - prices[j] );
                profits[j] += profit2;
            }

        for(int i = 1; i< prices.size()  ; i++){
            min1 = min(prices[i - 1], min1);
            profit1 = max(profit1, prices[i] - min1);
            if(profit1> 0)
                profits[i] += profit1;
            if(profits[i] > profit)
                profit = profits[i];
         }
        return profit;
   } 
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    /*int arr[ ROW ][ COL ] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
      vector<vector<int> > vec(ROW, vector<int>(COL));
      for(int i = 0 ; i< ROW; i++) 
      vec[i].assign(arr[i],arr[i]+COL);
      print2DVec(vec);*/
    int arr[] = {1,2,3}; 
    vector<int> vec;
    vec.assign(arr, arr+3);
    cout<<  sl->maxProfit(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
