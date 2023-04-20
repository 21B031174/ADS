#include <iostream>
using namespace std;
struct  heap
{
    int * a;
    int len;
    int capasity;
    heap(int capasity){
        this->capasity = capasity;
        len = 0;
        a = new int[capasity];
    }
    void heap_up(int i){
        int p_pos = (i-1)/2;
        if(a[p_pos]<a[i]){
            swap(a[i],a[p_pos]);
            heap_up(p_pos);
        }
    }
    void standartAdd(int x){
        a[len] = x;
        len+=1;
        heap_up(len-1);
    }
    int _heap_up(int i){
        int z = i;
        int p = (i-1)/2;
        if(a[p]<a[i]){
            swap(a[i],a[p]);
            z = _heap_up(p);
        }
        return z;
    }
    void create(int i , int x){
        a[i-1]+=x;
        cout<<_heap_up(i-1)+1<<endl;
    }
    void print(){
        for(int i=0;i<len;i++){
            cout<<a[i]<<" ";
        }
    }
};

int main(){
    int n,m,a,b,c;cin>>n;
    heap hp(1000);
    for(int i=0;i<n;i++){
        cin>>a;
        hp.standartAdd(a);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b>>c;
        hp.create(b,c);
    }
    hp.print();
    return 0;
}