#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long sum = 0;
int minim = 2;
int n, m;
vector <pair <int,pair <int,int> > > vec;
void rec(){
    if(minim <= n){
        for(int i=0;i<vec.size();i++){
            int a = vec[i].second.first;
            int b = vec[i].second.second;
            int len = vec[i].first;
            if(a < minim && minim <= b){
                sum += len;
                minim++;
                break;
            }
        }
        rec();
    }
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        vec.push_back(make_pair(z,make_pair(x,y)));
    }
    sort(vec.begin(),vec.end());
    rec();
    cout << sum;
    return 0;
}
