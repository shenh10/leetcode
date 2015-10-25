/*
Problem: Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Solution: At least it costs O(n^2)
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
        vector<vector<int> > threeSum(vector<int>& nums) {                
            vector< vector<int> > vec;
            if(nums.size()<=2)
                return vec;
            sort(nums.begin(), nums.end());
            int j, k;
            for(int i = 0; i < nums.size() - 2; ){
                j = i+1;
                k = nums.size() -1 ;
                while(j<k){
                    int _sum = nums[i] + nums[j] + nums[k]; 
                    if(_sum == 0){
                        vector<int> subVec;
                        subVec.push_back(nums[i]);
                        subVec.push_back(nums[j]);
                        subVec.push_back(nums[k]);
                        vec.push_back(subVec);
                        j++; k--;
                        while(j< nums.size() -1 && nums[j] == nums[j-1]) j++;
                        while(k> j && nums[k] == nums[k+1]) k--;

                    }else if(_sum < 0){
                        j++;
                    }else
                        k--;
                }
                i++;
                while(nums[i] == nums[i-1]) i++;
            }
            return vec;
        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> vec1, vec2;
    vector<vector<int> > vec;
    //    for(int i = 0; i< 10; i++) vec1.push_back(i);
    vec1.push_back(0);
    vec1.push_back(0);
    vec1.push_back(0);
    vec1.push_back(2);
    //  vec1.push_back(15);
    vec = sl-> threeSum(vec1); 
    cout<< "print array"<<endl;
    // printVec(vec2); 
    for(int i=0; i< vec.size(); i++) printVec(vec[i]);
    return 0;
}
