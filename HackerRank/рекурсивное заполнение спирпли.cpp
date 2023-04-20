#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 

using namespace std;

int arr[50][50];

int f(int a,int b=1,int u=0,int q=0){
    if(b>a*a)return 0;
    if(q<a){
        arr[u][q]=b;
        return f(a,b+1,u,q+1);
    }
    else if(u<a){
        arr[u][q]=b;
        return f(a,b+1,u+1,q);
    }
    



}
// 3 1 0 0         00  01  02
// 3 2 0 1         10  11  12
// 3 3 0 2         20  21  22  
// 3 4 1 2            
// 3 5 2 2 
// 3 6 2 1
// 3 7 2 0
// 3 8 1 0
// 3 9 1 1



int main(){
    int a,b,k=0;
    cin>>a;
    f(a);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}