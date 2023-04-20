#include <iostream>
using namespace std;
int cnt = 0;
struct hp{
    int *a;
    int len;
    int capacity;
    hp(int capacity){
        a = new int[capacity];
        this->capacity = capacity;
        len = 0;
    }

    void add(int x){
        a[len] = x;
        len++;
        heap_up(len - 1);
    }

    void heap_up(int i){
        if(i > 0){
            int p_pos = (i - 1) / 2;
            if(a[i] > a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }
    int print(){
        for (int i=0;i<len;i++){
            int l =i*2+1, r= i*2+2;
            if(l<len && r<len && a[l] < a[r]){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    int n;
    cin >> n;
    hp h(n);
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        h.add(j);
    }
    cout << h.print();
}