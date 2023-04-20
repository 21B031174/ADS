#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> vec(10000); 
vector<long> v; 
 
int chek(int a, int b){ 
    map<long, long> m;
    queue<pair<long, long>> q; 
    m[a] = -1;
    q.push({a, 0});
    while(q.size()!=0){
        int x = q.front().first; 
        int y = q.front().second; 
        q.pop(); 
        if(x == b){
            cout << y << endl;
            break;
        }
        vec[x] = 1; 
        if(!vec[x-1]){
            q.push({x-1, y+1});
            m[x-1] = x;
        }
        if(2*x < 10001 && !vec[2*x]){
            q.push({2*x, y+1});
            m[2*x] = x;
        } 
    } 
    v.push_back(b); 
    while(true){ 
        if(v[v.size()-1] == a)break; 
        else v.push_back(m[v[v.size()-1]]); 
    } 
} 
 
int main(){ 
    int a, b;
    cin >> a >> b;
    chek(a, b);
    for(int i = v.size()-2; i >= 0; i--){
        cout << v[i] << ' ';
    } 
}