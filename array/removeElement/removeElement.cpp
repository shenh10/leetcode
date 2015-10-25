/*
    How to use vector iterator erase
    Edge case: erase last element
*/


#include "iostream"
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        for(vector<int>::iterator it = nums.begin(); it!=nums.end(); ){
            if (*it == val){
                if(it+1 == nums.end()){
                    nums.pop_back();
                    break;
                    
                }
                else
                    it = nums.erase(it);
            }else
                it++;
        }
        return nums.size();
    }
};


int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> myvector;
    for (int i=1; i<=10; i++) myvector.push_back(1);
    for (int i=5; i<=11; i++) myvector.push_back(1);
    //myvector.push_back(1);
    cout<< sl->removeElement(myvector, 1)<<endl;
    for(int i=1; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
