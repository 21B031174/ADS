#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int p[200000];
int r[200000];

int chek(int k){
    if(k==p[k])return k;
    return p[k] = chek(p[k]);
}

bool f(int i, int j){
    int a = chek(i);
    int b = chek(j);
    if(a == b)return false;
    p[a] = b;
    return true;
}



int main(){
    int n, m;
    cin >> n >> m;

   vector <vector <int> > vec(n); 

    for(int i=0;i<n;i++){
        p[i] = i;
        r[i] = i;
    }
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        vec[x].push_back(y);
        vec[y].push_back(x);
    
    }

    stack<int> st;
    
    int cnt = 0;

    for(int i = n-1; i >= 0; i--){
        st.push(cnt);
        cnt++;
        for(int j=0;j<vec[i].size();j++){ 
            if(vec[i][j] > i){
                if(f(i, vec[i][j]))cnt--;
            }
        }
    }
    int len = st.size();
    for(int i=0;i<len;i++){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
    
}