/*
Problem:

Determine whether an integer is a palindrome. Do this without extra space
*/

#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
void printVec(vector<int> vec){
    for (int i = 0; i< vec.size(); i++){
        cout<< vec[i]<<" ";

    }
    cout<<endl;
}

#define BASE 10
class Solution {
    public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
       }
       int bits = log10(x);
       while( x > 0 && bits >=1 ){
            int head = x/pow(BASE, bits);
            int tail = x % BASE; 
            cout<<"head = "<<head << " tail = "<<tail<<endl;
            if( head != tail){

                return false;
            }
            x -= head * pow(BASE, bits);
            x /= BASE;
            bits -=2;
        } 
        return true;
    }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    bool bl = sl->isPalindrome(-2147483648);
    cout<<(bl == true? 1 :0);
    return 0;
}
