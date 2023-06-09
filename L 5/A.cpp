#include <iostream>

using namespace std;

struct hp{
    long long * a;
    long long capacity;
    long long length;

public:
    hp(long long capacity){
        a = new long long[capacity];
        this->capacity = capacity;
        length = 0;
    }

    void add(long long x){
        _add(x);
    }

    long long cut_min(){
        long long sum=0;
        long long res1 = a[0];
        _cut_min();
        long long res2 = a[0];
        _cut_min();
        sum += res1+res2;
        _add(sum);
        return sum;
    }
    

private:
    
    void _add(long long x){
        a[length]  = x;
        length++;
        heap_up(length - 1);
    }

    void heap_up(long long i){
        if(i>0){
            long long p_pos = (i-1)/2;
            if(a[i] < a[p_pos]){
                swap(a[i],a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void _cut_min(){
        a[0] = a[length -1];
        if(length - 1>0){
            length = length - 1;
        }
        else{length = 0;}
        heap_down(0);
    }

    void heap_down(long long i){
        long long l = 2 * i + 1;
        long long r = 2 * i + 2;
        long long min_pos = i;
        if(l < this->length && a[min_pos] > a[l]) min_pos = l;
        if(r < this->length && a[min_pos] > a[r]) min_pos = r;
        if(i != min_pos) {
            swap(a[i], a[min_pos]);
            heap_down(min_pos);
        }
    }
};

int main(){
    long long a,b,sum=0;cin>>a;
    hp h(1000000);
    for(long long i=0;i<a;i++){
        cin>>b;
        h.add(b);
    }
    for(long long i = 0; i < a-1; ++i){
       sum+=h.cut_min();
    }
    cout<<sum;
}