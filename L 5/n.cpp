#include <iostream>
using namespace std;
struct heap{

    long long * arr;
    long long lenght;
    long long capacity;
    long long Total_sum=0;

    heap(int capasity){
        this->capacity = capasity;
        this->arr = new long long[capasity];
        this->lenght = 0;
    }

    void heap_up(long long i){
        long long pre = (i-1)/2;
        if(arr[i]<arr[pre]){
            swap(arr[i], arr[pre]);
            heap_up(pre);
        }
    }

    void add(long long x){
        arr[lenght]=x;
        lenght+=1;
        heap_up(lenght-1);

    }

    void heap_down(long long i){
        long long l ,r ,min_pos=i;
        l = 2*i+1;
        r = 2*i+2;
        if(l<lenght && arr[l]<arr[min_pos]){min_pos = l;}
        if(r<lenght && arr[r]<arr[min_pos]){min_pos = r;}
        if(i!=min_pos){
            swap(arr[min_pos], arr[i]);
            heap_down(min_pos);
        }
    }
    
    long long cut_min(){
        long long res = arr[0];
        arr[0] = arr[lenght-1];
        lenght=lenght-1;
        heap_down(0);
        return res;
    }
    long long problem1(){
        long long x = cut_min();
        long long y = cut_min();
        Total_sum+=(x+y);
        add((x+y));
        if(lenght>=2){
            problem1();
        }
        return Total_sum;
    }
};

int main(){
    heap hp(1000000);
    long long n;cin>>n;
    for(long long i=0;i<n;i++){
        long long x;cin>>x;
        hp.add(x);
    }
    cout<<hp.problem1();
}