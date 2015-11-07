/*
Problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

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
        int maxProfit(int k, vector<int>& prices) {
            if (prices.size() < 2) return 0;
            int days = prices.size();
            if(k >= days)
                return profits_unlimited(prices);
            vector<vector<int> > global, local;
            global.resize(days);
            for(int i = 0; i < days; i++){
                global[i].resize(k+1);
            }
            local.resize(days);
            for(int i = 0; i < days; i++){
                local[i].resize(k+1);
            }
            for(int i = 1; i< days; i++){
                int diff = prices[i] - prices[i-1];
                for(int j = 1; j <=k; j++){
                    local[i][j] = max( global[i-1][j-1] +max(diff, 0), local[i-1][j] +diff);
                    global[i][j] = max( global[i-1][j] , local[i][j]);

                }

            }
            return global[days-1][k];
        } 
        int profits_unlimited(vector<int> &prices){
            int profit = 0;
            for( int i = 0; i < prices.size()-1; i++){
                profit += max(prices[i+1] - prices[i], 0);
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
    cout<<  sl->maxProfit(1,vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
