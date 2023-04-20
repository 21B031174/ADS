#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> d;
    bool ok=true;
    while(ok){
        char c;cin>>c;
        if(c=='+'){
            int a;cin>>a;
            d.push_front(a);
        }
        else if(c=='-'){
            int a;cin>>a;
            d.push_back(a);
        }
        else if(c=='*'){
            if(d.empty()){
                cout<<"error"<<endl;
            }
            else{
                cout<<d.front()+d.back()<<endl;
                d.pop_back();
                if(!d.empty()){
                    d.pop_front();
                }
            }
        }
        else if(c=='!'){
            ok= false;
        }
    }
}