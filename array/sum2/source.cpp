/*
Problem: Given an array of integers, find two numbers such that they add up to a specific target number.
Solution: Use hashmap to get O(n) efficiency
*/

#include "iostream"
#include <vector>
#include <map>
using namespace std;
void printVec(vector<int> vec){
    for (int i = 0; i< vec.size(); i++){
        cout<< vec[i]<<" ";

    }
    cout<<endl;
}


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> vec;
            map<int, vector<int> > mymap;
            for(int i = 0; i< nums.size(); i++){
                vector<int> subvec;
                if(mymap.find(nums[i])!= mymap.end()){
                    subvec = mymap[nums[i]];
                    subvec.push_back(i);
                    mymap[nums[i]] = subvec;
                }else{
                    subvec.push_back(i);
                    mymap[nums[i]] = subvec;
                }        
            }
            map<int, vector<int> >::iterator it = mymap.begin();
            int count = 0;
            for(; it != mymap.end(); ++it, count++){
                int rest = target - it->first;
                map<int, vector<int> >::iterator it2 = mymap.find( rest );
                if( it2 != mymap.end() ){
                    vector<int> act1, act2;
                    int key1, key2;
                    act1 = it->second;
                    act2 = it2->second;
                    if(it == it2){ // 2 same values in array
                        if(act1.size() == 1)
                            return vec;
                        key1 = act1[0];
                        key2 = act1[1];
                    }else{
                        key1 = act1[0];
                        key2 = act2[0];
                    }

                    if(key1 < key2){
                        vec.push_back(key1 + 1);
                        vec.push_back(key2 + 1);
                    }else{

                        vec.push_back(key2 + 1);
                        vec.push_back(key1 + 1);
                    }
                    break; 
                }
            }
            return vec;

        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> vec1, vec2;
    //    for(int i = 0; i< 10; i++) vec1.push_back(i);
    vec1.push_back(0);
    vec1.push_back(4);
    vec1.push_back(3);
    vec1.push_back(0);
    //  vec1.push_back(15);
    vec2 = sl-> twoSum(vec1, 0); 
    cout<< "print array"<<endl;
    printVec(vec2); 
    // for(int i=0; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
