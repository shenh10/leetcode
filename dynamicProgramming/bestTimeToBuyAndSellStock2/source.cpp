/*
Problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
        int profit = 0;
        int buyPrice = 0;
        bool buyflag = false;
        if(prices.size() == 0) return profit;
        for(int i = 0; i < prices.size() -1; i ++ ){
            if( prices[i + 1] > prices[i]){
                if(!buyflag){
                    // not buy, then buy one. make profit if sell it out next day
                    buyPrice = prices[i];
                    buyflag = true;
                }else {
                    //continue holds for high profit
                    continue;
                }
            }
            else{
                if(!buyflag){
                    // buy tmr make more profit.
                    continue;
               }else{
                    // tmr price lower. sell it out
                    profit += prices[i] - buyPrice;
                    buyflag = false;     
                }
            }
        }        
        if(buyflag){
            profit += prices[prices.size()-1] - buyPrice;

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
    int arr[] = {6, 5, 9, 7, 3, 4 , 3};
    vector<int> vec;
    vec.assign(arr, arr+7);
    cout<<  sl->maxProfit(vec);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
