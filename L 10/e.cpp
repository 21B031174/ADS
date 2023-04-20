#include <iostream>
using namespace std;
int main(){
    int n,m,a,b,c,k;
    cin>>n>>m;
    bool arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>k;
            arr[i][j]=k;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        a--;b--;c--;
        if(arr[a][b] && arr[b][c] && arr[a][c]){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
}