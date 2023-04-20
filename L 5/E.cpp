#include <iostream>
using namespace std;
struct heap{
    int * arr;
    int lenght;
    int capacity;
    long Total_sum=0;
    heap(int capasity){
        this->capacity = capasity;
        this->arr = new int[capasity];
        this->lenght = 0;
    }
    void heap_up(int i){
        int pre = (i-1)/2;
        if(arr[i]<arr[pre]){
            swap(arr[i], arr[pre]);
            heap_up(pre);
        }
    }
    void add(int x){
        arr[lenght]=x;
        lenght+=1;
        heap_up(lenght-1);

    }
    void heap_down(int i){
        int l ,r ,min_pos=i;
        l = 2*i+1;
        r = 2*i+2;
        if(l<lenght && arr[l]<arr[min_pos]){min_pos = l;}
        if(r<lenght && arr[r]<arr[min_pos]){min_pos = r;}
        if(i!=min_pos){
            swap(arr[min_pos], arr[i]);
            heap_down(min_pos);
        }
    }
    int cut_min(){
        int res = arr[0];
        arr[0] = arr[lenght-1];
        lenght=(0>lenght-1)?0:lenght-1;
        heap_down(0);
        return res;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    heap hp(1000000);
    while (n!=0) {
        string command;cin>>command;
        if(command=="insert"){
            int z;cin>>z;
            if(hp.lenght==k){
                int save = hp.cut_min();
                if(save>z){
                    hp.add(save);
                }
                else{
                    hp.add(z);
                }
            }
            else{hp.add(z);}
        }
        if(command=="print"){
            int Total_sum=0;
            for(int i=0;i<hp.lenght;i++){
                Total_sum+=hp.arr[i];
            }
            cout<<Total_sum<<endl;
        }
        n--;
    }
}