/*
   Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

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
        vector<vector<int> > fourSum(vector<int>& nums, int target) {                
            vector< vector<int> > vec;
            if(nums.size()<=3)
                return vec;
            sort(nums.begin(), nums.end());
            int j, k;
            for(int i = 0; i < nums.size() - 3; ){
                for( int l = i + 1; l < nums.size() -2; )
                {
                    j = l+1;
                    k = nums.size() -1 ;
                    while(j<k){
                        int _sum = nums[i] + nums[l] + nums[j] + nums[k]; 
                        if(_sum == target){
                            vector<int> subVec;
                            subVec.push_back(nums[i]);
                            subVec.push_back(nums[l]);
                            subVec.push_back(nums[j]);
                            subVec.push_back(nums[k]);
                            vec.push_back(subVec);
                            j++; k--;
                            while(j< nums.size() -1 && nums[j] == nums[j-1]) j++;
                            while(k> j && nums[k] == nums[k+1]) k--;

                        }else if(_sum < target){
                            j++;
                        }else
                            k--;
                    }
                    l++;
                    while(nums[l] == nums[l-1]) l++;
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
    vec1.push_back(1);
    vec1.push_back(0);
    vec1.push_back(-1);
    vec1.push_back(0);
    vec1.push_back(-2);
    vec1.push_back(2);
    //  vec1.push_back(15);
    vec = sl-> fourSum(vec1,0); 
    cout<< "print array"<<endl;
    // printVec(vec2); 
    for(int i=0; i< vec.size(); i++) printVec(vec[i]);
    return 0;
}
