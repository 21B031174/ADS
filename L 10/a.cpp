#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int arr[1001][1001];
queue<pair<int, int> > q;
int globalCnt=0;


int main(){
    int n,m,cnt=0;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                q.push(make_pair(i,j));
            }
            else if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    
    while(true){
        int len = q.size();
        for(int i=0;i<len;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(y+1<=m && arr[x][y+1]==1){
                cnt--;
                arr[x][y+1]=2;
                q.push(make_pair(x,y+1));
            }
            if(y-1>=0 && arr[x][y-1]==1){
                cnt--;
                arr[x][y-1]=2;
                q.push(make_pair(x,y-1));
            }
            if(x+1<=n && arr[x+1][y]==1){
                cnt--;
                arr[x+1][y]=2;
                q.push(make_pair(x+1,y));
            }
            if(x-1>=0 && arr[x-1][y]==1){
                cnt--;
                arr[x-1][y]=2;
                q.push(make_pair(x-1,y));
            }
        }
        if(q.empty()){
            break;
        }
        globalCnt++;
    }
    if(cnt!=0){
        cout<<-1;
        return 0;
    }
    cout<<globalCnt;
    return 0;
}