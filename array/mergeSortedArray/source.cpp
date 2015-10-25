/*

Problem: Given an index k, return the kth row of the Pascal's triangle.
O(k) spatial limits.
Solution: Due to spatial limit, only rolling accumulation accepted.
*/

#include "iostream"
#include <vector>
using namespace std;
void printVec(vector<int> vec){
    for (int i = 0; i< vec.size(); i++){
        cout<< vec[i]<<" ";

    }
    cout<<endl;
}


class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            nums1.resize(m+n);
            int iter1 = m-1, iter2 = n-1, iter3 = m + n - 1;
            while(iter1 >= 0 || iter2 >= 0){
                if( iter1 < 0 && iter2 >= 0 ){
                    while( iter2 >= 0 ){
                        nums1[iter3] = nums2[iter2];
                        iter2 --;
                        iter3 --;
                    }
                    break;
                }
                if( iter2 < 0 && iter1 >= 0 ){
                    while( iter1 >= 0 ){
                        nums1[iter3] = nums1[iter1];
                        iter1 --;
                        iter3 --;
                    }
                    break;
                }

                if( nums2[ iter2 ] >= nums1[ iter1 ] ){
                    nums1[ iter3 ] = nums2[ iter2 ];

                    //    cout<<"compare nums1 and nums2"<< nums1[iter1]<<" "<<nums2[iter2]<<" "<< nums1[iter3]<< endl;
                    iter2 --;
                }else{
                    //  cout<<"compare nums1 and nums2"<< nums1[iter1]<<" "<<nums2[iter2]<<" "<< nums1[iter3] << endl;
                    nums1[ iter3 ] = nums1[ iter1 ];
                    iter1 --;
                }
                iter3--;

            }
        }
};
int main( int argc, char* argv[]){
    Solution* sl = new Solution();
    vector<int> vec1, vec2;
    for(int i = 0; i< 10; i++) vec1.push_back(i);
    for(int i = 0; i< 20; i++) vec2.push_back(i-5);

    sl-> merge(vec1, vec1.size(), vec2, vec2.size());
    cout<< "print array"<<endl;
    printVec(vec1); 
    // for(int i=0; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
