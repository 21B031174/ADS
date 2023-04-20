#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxArea(vector<int>& hi){
    int max=0;
    for(int i=0;i<hi.size();i++){
        for(int j=i+1;j<hi.size();j++){
            int k = (j-i) * min(hi[i],hi[j]);
            if(max<k)max=k;
        }
    }
    return max;
}


int main(){
    vector<int> myvector;
    myvector.push_back (1);
    myvector.push_back (8);
    myvector.push_back (6);
    myvector.push_back (2);
    myvector.push_back (5);
    myvector.push_back (4);
    myvector.push_back (8);
    myvector.push_back (3);
    myvector.push_back (7);
    cout<<maxArea(myvector);
}
