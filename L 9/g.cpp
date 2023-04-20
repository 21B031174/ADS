#include <iostream>
#include <vector>

using namespace std;

vector <int> f(string str) {
    int n = str.size();
    vector <int> v(n);
    v[0]=0; 
    int l=0,r=0;
    for(int i = 1;i < n;i++) {
        if(i <= r){
            v[i] = min(v[i - l], r - i + 1);
        }
        while(i+v[i]<n && str[v[i]]==str[i+v[i]]){
            v[i]++;
        }
        if(i+v[i]-1>r) {
            l = i;
            r = i + v[i] - 1;
        }
    }
    return v;
} 

int main(){
    string str;
    cin >> str;
    vector <int> v = f(str);
    v[0] = str.size();
    for(int i = 1; i <= str.size(); i ++) {
        bool check = 1;
        for(int j = 0; j < str.size() - (str.size() % i); j += i) {
            if(v[j] >= i);
            else{
                check = 0;
                break;
            }
        }
        if(str.size() % i != 0){
            if(v[str.size() - (str.size() % i)] != (str.size() % i)) check = 0;
        }
        if(check == 1){
            cout << i;
            return 0;
        }
    }
    return 0;
}