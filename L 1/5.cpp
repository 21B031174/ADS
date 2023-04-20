#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque <int> d1;
    deque <int> d2;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        d1.push_back(a);
    }
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        d2.push_back(a);
    }
    int i=0;
    while(true){
        if(d1.empty()){
            cout<<"Nursik "<<i;
            return 0;
        }
        if(d2.empty()){
            cout<<"Boris "<<i;
            return 0;
        }
        if(d1.front()==0 && d2.front()==9){
            d1.push_back(d1.front());
            d1.push_back(d2.front());
            d1.pop_front();
            d2.pop_front();
        }
        else if(d2.front()==0 && d1.front()==9){
            d2.push_back(d1.front());
            d2.push_back(d2.front());
            d1.pop_front();
            d2.pop_front();
        }
        else if(d1.front()>d2.front()){
            d1.push_back(d1.front());
            d1.push_back(d2.front());
            d1.pop_front();
            d2.pop_front();
        }
        else{
            d2.push_back(d1.front());
            d2.push_back(d2.front());
            d1.pop_front();
            d2.pop_front();
        }
        i++;
    }
}