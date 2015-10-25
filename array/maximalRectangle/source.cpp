/*
Problem:
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void printVec(vector<int> vec){
    for (int i = 0; i< vec.size(); i++){
        cout<< vec[i]<<" ";

    }
    cout<<endl;
}


class Solution {
    public:
        int largestRectangleArea(vector<int>& height) {
            vector<int> mystack;
            int maxArea = 0, deep = 1;
            height.push_back(0);
            for (int i = 0; i< height.size(); ){
                if(mystack.empty() || height[i] > height[mystack.back()]){
                    mystack.push_back(i);
                    i++;
                    continue;
                }else{
                    int top = mystack.back();
                    mystack.pop_back();
                    maxArea = max(maxArea, height[top]*(mystack.empty()? i:( i - mystack.back() - 1)) );
                }
            }
            return maxArea;        
        }
        int maximalRectangle(vector<vector<char> >& matrix) {
            int len = matrix.size();
            int maxArea = 0;
            for(int i = 0; i< len; i++){
                vector<int> histogram;
                for(int k = 0; k < matrix[i].size(); k ++)
                {
                    int j = i, count = 0;
                    while( j >= 0 && matrix[j][k] != '0') { count++; j--; }  
                    histogram.push_back(count);
                }
                maxArea = max(maxArea, largestRectangleArea(histogram));  
            }
return maxArea;
        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> vec1, vec2;
    //for(int i = 0; i< 10; i++) vec1.push_back(i);
    //for(int i = 0; i< 10; i++) vec1.push_back(i);
    //char arr[4][4] = {{'0','0','0','0'},{'1','1','1','1'},{'1','1','1','0'},{'0','1','0','0'}};
    char arr[2][1] ={ {'1'},{'1'}};
    vector<vector<char> > vec;

 vec.push_back(vector<char>(begin(arr[0]),end(arr[0])));
vec.push_back(vector<char>(begin(arr[1]), end(arr[1])));
    //vec1.push_back(2);
    // vec1.push_back(1);
    // vec1.push_back(5);
    // vec1.push_back(6);
    // vec1.push_back(2);
    // vec1.push_back(3);
    //  vec1.push_back(15);
    cout <<sl-> maximalRectangle(vec); 
   // cout<< "print array"<<endl;
    // printVec(vec2); 
    //for(int i=0; i< vec.size(); i++) printVec(vec[i]);
    return 0;
}
