#include <iostream>

using namespace std;

struct hp{
    long long * a;
    long long capacity;
    long long len;
    long long fans;
    long long sum=0;

    hp(long long capacity, long long fans){
        a = new long long[capacity];
        this->capacity = capacity;
        len = 0;
        this->fans = fans;
    }

    void add(long long x){
        a[len] = x;
        len++;
        heap_up(len - 1);
    }

    void heap_up(long long i){
        if(i > 0){
            long long p_pos = (i - 1) / 2;
            if(a[i] > a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void print(){
        long long p = cut_max();
        sum+=p;
        p-=1;
        fans -= 1;
        add(p);
        if(fans == 0){
            cout<<sum;
        }
        else print();

    }

    long long cut_max(){
        long long res = a[0];
        a[0] = a[len-1];
        len = (len-1>0)?len-1:0;
        heap_down(0);
        return res;
    }

    void heap_down(long long i){
        long long l = 2 * i + 1;
        long long r = 2 * i + 2;
        long long min_pos = i;
        if(l < this->len && a[min_pos] < a[l]) min_pos = l;
        if(r < this->len && a[min_pos] < a[r]) min_pos = r;
        if(i!=min_pos){
            swap(a[i],a[min_pos]);
            heap_down(min_pos);
        }
    }

};


int main(){
    long long a,b,c;cin>>a>>b;
    hp h(100000,b);
    for(long long i=0;i<a;i++){
        cin>>c;
        h.add(c);
    }
    h.print();
}