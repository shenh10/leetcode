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
#define THOUSAND 1000
#define MILLION 1000000
#define BILLION 1000000000 
class Solution {
    public:
        string numberToWords(int num) {
            map<int, string> dict;
            buildMap(dict);
            if(num == 0) return dict[0];
            return findNumberToWords(num, dict);
        }
        string findNumberToWords(int num, map<int, string> &dict){
            if(num == 0) return "";
            if(num >0 && num <= 20) return dict[num];
            if( num > 20 && num <= 99){
                int end = num%10;
                int start = num/10;
                if(end == 0) return dict[start*10];
                else
                    return dict[start*10] +" " + dict[end];
            }
            if(num >=100 && num <= 999){
                string s = findNumberToWords(num%100, dict);
                if(s.length() == 0)
                    return dict[num/100] + " "+ dict[100] ;
                else
                    return dict[num/100] + " "+ dict[100] + " " + s ;
            }
            if(num >= THOUSAND && num <= 999999){
                string s = findNumberToWords(num%THOUSAND, dict);
                if(s.length() != 0)
                    return findNumberToWords(num/THOUSAND, dict) + " " + dict[THOUSAND] + " " + s;
                else 
                    return findNumberToWords(num/THOUSAND, dict) + " " + dict[THOUSAND];
            }
            if(num >= MILLION && num <= 999999999){
                string s = findNumberToWords(num%MILLION, dict);
                if(s.length() != 0)
                    return findNumberToWords(num/MILLION, dict) + " " + dict[MILLION] + " "+ s;
                else
                    return findNumberToWords(num/MILLION, dict) + " " + dict[MILLION] ;
            }
            if(num >= BILLION){
                string s = findNumberToWords(num%BILLION, dict);
                if(s.length() != 0)
                    return findNumberToWords(num/BILLION, dict) + " "+ dict[BILLION] +" "+ s;
                else

                    return findNumberToWords(num/BILLION, dict) + " "+ dict[BILLION];
            }
            return "";
        }
        void buildMap(map<int, string> &dict){
            dict[0] = "Zero";
            dict[1] = "One";
            dict[2] = "Two";
            dict[3] = "Three";
            dict[4] = "Four";
            dict[5] = "Five";
            dict[6] = "Six";
            dict[7] = "Seven";
            dict[8] = "Eight";
            dict[9] = "Nine";
            dict[10] = "Ten";
            dict[11] = "Eleven";
            dict[12] = "Twelve";
            dict[13] = "Thirteen";
            dict[14] = "Fourteen";
            dict[15] = "Fifteen";
            dict[16] = "Sixteen";
            dict[17] = "Seventeen";
            dict[18] = "Eighteen";
            dict[19] = "Nineteen";
            dict[20] = "Twenty";
            dict[30] = "Thirty";
            dict[40] = "Forty";
            dict[50] = "Fifty";
            dict[60] = "Sixty";
            dict[70] = "Seventy";
            dict[80] = "Eighty";
            dict[90] = "Ninety";
            dict[100] = "Hundred";
            dict[THOUSAND] = "Thousand";
            dict[MILLION] = "Million";
            dict[BILLION] = "Billion";
        }
};
#define ROW 4
#define COL 5
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    int arr[] = {2, 1};
    int arr2[] = {2,3,1,2,4,3,31,43,54,1,2,35,4,2,43,6,12,43};
    vector<int> vec, vec2;
    vec.assign(arr, arr+2);
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
    printVec(vec);
    cout << sl->numberToWords(1234567891);
    //printVec(rv);
    // cout<<(bl == true? 1 :0);
    return 0;
}
