/*
    Problem:  Given a non-negative number represented as an array of digits, plus one to the number.
    Leetcode compiler doesn't support insert at begining.
*/

#include "iostream"
#include <vector>
using namespace std;
class Solution {
    public:
          vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0)
            return digits;
        vector<int>::reverse_iterator rit = digits.rbegin();
        vector<int> returnedVector;
        for( ;rit!= digits.rend(); ){
            if(*rit == 9){
                *rit = 0;
                rit++;
                if(rit == digits.rend()){
                    returnedVector.push_back(1);
                }
            }else{
                *rit +=1;
                break;
            }
        }
        returnedVector.insert(returnedVector.end(),digits.begin(),digits.end());
        return returnedVector;
    }
        };


int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> myvector;
    //for (int i=1; i<=8; i++) myvector.push_back(9);
    myvector.push_back(9);
   // myvector.push_back(0);
    //for (int i=2; i<=2; i++) myvector.push_back(2);
    //for (int i=5; i<=11; i++) myvector.push_back(2);
    //myvector.push_back(1);
    //cout<< sl->plusOne(myvector)<<endl;
    myvector = sl->plusOne(myvector);
    cout<< "print array"<<endl;
    for(int i=0; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
