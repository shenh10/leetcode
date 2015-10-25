/*

Problem: Given an index k, return the kth row of the Pascal's triangle.
O(k) spatial limits.
Solution: Due to spatial limit, only rolling accumulation accepted.
*/

#include "iostream"
#include <vector>
using namespace std;
class Solution {
    public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
         vector<int> vec;
         vec.resize(rowIndex);
         for(int i = 0; i< rowIndex; i++){
            vec[i] = 1;
            for(int j = i-1; j>0; j --){
                vec[j] = vec[j] + vec[j-1];
            }
         }
         return vec;
    }

   };
void printVec(vector<int> vec){
    for (int i = 0; i< vec.size(); i++){
          cout<< vec[i]<<" ";

    }
    cout<<endl;
}

int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    if(argc < 2){
        cout<<"usage: please input the layer number.";
        return 0;    
    }
    vector<int> vec = sl->getRow(stoi(argv[1]));
    cout<< "print array"<<endl;
        printVec(vec); 
   // for(int i=0; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
