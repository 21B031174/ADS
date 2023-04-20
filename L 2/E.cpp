#include <iostream>

using namespace std;

struct node{
    string vall;
    node * p;
    node * next;
    int cnt;
    node(string vall) {
        this->vall=vall;
        p=nullptr;
        next=nullptr;
        cnt=0;
    }
};

class LinkedL{
public:
    node * head;
    node * tail;
    int k;
    LinkedL() {
        head=tail=nullptr;
        k=0;
    }

    void add(string vall) {
        node * nod = new node(vall);
        if(head==nullptr) {
            head=tail=nod;
            k=1;
        }
        else{
            if(head->vall==vall) {
                head->cnt++; 
            }
            else if(head->p==nullptr) {
                head->p=nod;
                nod->next=head;
                head=nod;
                k++; 
            }
        }
    }
    void print() {
        node * c = head;
        cout<<"All in all: "<<k<<endl;
        cout<<"Students:"<<endl;
        while(c!=nullptr) {
            cout<<c->vall<<endl;
            c=c->next;
        }
    }
};

int main() {
    LinkedL ll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        while(cin>>s){
            ll.add(s);
        }
    }
    ll.print();
}