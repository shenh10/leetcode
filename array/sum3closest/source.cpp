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
        int threeSumClosest(vector<int>& nums, int target) {              
            if(nums.size()<=2)
                return 0;
            sort(nums.begin(), nums.end());
          //  printVec(nums);
            int j, k;
            int closetSum = nums[0] + nums[1] + nums[2];
            for(int i = 0; i < nums.size() - 2; ){
                j = i+1;
                k = nums.size() -1 ;
                while(j<k){
                    int _sum = nums[i] + nums[j] + nums[k]; 
                        if(abs(closetSum - target)> abs(_sum - target) ){
                             closetSum = _sum;
                        }
                    if(_sum == target){
                        return target;
                    }else if(_sum < target){ 
                            j++;
                        }else
                            k--;
                    }
                
                i++;
               // while(nums[i] == nums[i-1]) i++;
            }
            return closetSum;
        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> vec1, vec2;
    vector<vector<int> > vec;
    //    for(int i = 0; i< 10; i++) vec1.push_back(i);
    vec1.push_back(-1);
    vec1.push_back(2);
    vec1.push_back(1);
   // vec1.push_back(-4);
    //  vec1.push_back(15);
    //vec = sl-> threeSum(vec1); 
    cout<< sl->threeSumClosest(vec1, 1);
    cout<< "print array"<<endl;
    // printVec(vec2); 
   // for(int i=0; i< vec.size(); i++) printVec(vec[i]);
    return 0;
}
