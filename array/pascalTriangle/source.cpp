/*
Problem: Given numRows, generate the first numRows of Pascal's triangle
*/

#include "iostream"
#include <vector>
using namespace std;
class Solution {
    public:
   vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vec;
        if(numRows <= 0)
            return vec;
        generateLayerK(vec, numRows);
        return vec;
    }
    vector<int> generateLayerK(vector<vector<int> > &vec,  int layer){
        vector<int> thisLayer;
        if(layer == 1){
            thisLayer.push_back(1);
            vec.push_back(thisLayer);
            return thisLayer;
        }
        vector<int> lastLayer = generateLayerK(vec, layer-1);
        for( int i = 0; i< layer; i++ ){
            if( i == 0 || i == layer - 1){
                thisLayer.push_back(1);
                continue;
            }
            thisLayer.push_back(lastLayer[i-1]+lastLayer[i]);
        }
        vec.push_back(thisLayer);
        return thisLayer;
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
    vector<vector<int> > vec = sl->generate(stoi(argv[1]));
    cout<< "print array"<<endl;
    for (int i = 0; i< vec.size(); i++){
        printVec(vec[i]); 
    }
   // for(int i=0; i< myvector.size(); i++) cout<<myvector[i]<<endl;
    return 0;
}
