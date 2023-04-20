#include <iostream>
#include <vector>

using namespace std;

vector<int> f(string str){
    int n = str.size();
    vector<int> v(n);
    v[0] = 0;
    for(int i = 1; i < n; ++i){
        int j = v[i - 1];
        while(j > 0 && str[j] != str[i]){
            j = v[j-1];
        }
        if(str[i] == str[j]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){
    int n,k;
    cin >> n;
    string s1;
    for(int i=0;i<n;i++) {
        cin >> s1>>k;
        string str = s1;
        str.pop_back();
        str = str + '#' + s1;
        vector<int> v = f(str);
        int a = v.back();
        cout << s1.size() + (s1.size() - a) * (k - 1) << endl;
    }
    return 0;
}