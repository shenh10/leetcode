/*
Problem:
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
The array may contain duplicates
Solution: At least it costs O(logn)~O(logn) Binary Partition
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
     int findMin(vector<int>& nums) {
            int length = nums.size();
            return findMinRecusive(nums, 0, length -1);
        }
     int   findMinRecusive(vector<int> &nums, int start, int end){
            if( start == end || start == end -1)
                return nums[start] > nums[end]? nums[end]: nums[start];
            int middle = (start + end)/2;
            if(nums[middle] < nums[end])
                return findMinRecusive(nums, start, middle);
            else if(nums[middle] > nums[end])
                return findMinRecusive(nums, middle, end);
            else{
                    int a = findMinRecusive(nums, start, middle);
                    int b = findMinRecusive(nums, middle, end);
                    return a < b ? a:b;
                } 
        }
       };
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> vec1, vec2;
    vector<vector<int> > vec;
    //for(int i = 0; i< 20; i++) vec1.push_back(10);
    //for(int i = 0; i< 10; i++) vec1.push_back(i);
    //for(int i = 0; i< 10; i++) vec1.push_back(10);
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(3);
//    vec1.push_back(7);
    //  vec1.push_back(15);
    cout <<sl-> findMin(vec1); 
    cout<< "print array"<<endl;
    // printVec(vec2); 
    //for(int i=0; i< vec.size(); i++) printVec(vec[i]);
    return 0;
}
