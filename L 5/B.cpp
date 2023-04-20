#include <iostream>

using namespace std;

struct hp{
private:
    int * a;
    int capacity;
    int length;

    void heap_up(int i){
        if(i > 0){
            int p_pos = (i - 1) / 2;
            if(a[i] > a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if(l < this->length && a[min_pos] < a[l]) min_pos = l;
        if(r < this->length && a[min_pos] < a[r]) min_pos = r;
        if(i != min_pos) {
            swap(a[i], a[min_pos]);
            heap_down(min_pos);
        }
    }

    void _cut_min(){
        a[0] = a[length - 1];
        length = max(length - 1, 0);
        heap_down(0);
    }

    void _add(int x){
        a[length] = x;
        length++;
        heap_up(length - 1);
    }

public:
    hp(int capacity){
        a = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }
    
    int cut_min(){
        int res = a[0];
        _cut_min();
        return res;
    }

    void add(int x){
        _add(x);
    }

    void print(){
        if(length>1){
            int x = cut_min();
            int y = cut_min();
            if(x!=y)add(x-y);
            print();
        }
        else if(length == 1)cout<<a[0];
        else cout<< 0 ;
    }  
};
int main(){

    int a,b;cin>>a;
    hp h(100);

    for(int i = 0; i < a; ++i){
        cin>>b;
        h.add(b);
    }
    h.print();
    return 0;
}