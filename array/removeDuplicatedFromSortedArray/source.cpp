#include "iostream"
#include <vector>
using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() == 0)
                return 0;
            vector<int>::iterator it_prev= nums.begin()+1;
            vector<int>::iterator it_post= nums.begin();
            for(;it_prev!=nums.end() && it_post!=nums.end();){
                if(*it_prev == *it_post)
                    it_prev = nums.erase(it_prev);
                else{
                    it_post = it_prev;
                    it_prev ++;
                }
            }
            return nums.size();   
        }
};


int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> myvector;
    for (int i=1; i<=4; i++) myvector.push_back(1);
    for (int i=2; i<=2; i++) myvector.push_back(2);
    //for (int i=5; i<=11; i++) myvector.push_back(2);
    //myvector.push_back(1);
    cout<< sl->removeDuplicates(myvector)<<endl;
    cout<< "print array"<<endl;
    for(int i=0; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
