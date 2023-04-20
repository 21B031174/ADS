#include <iostream>

using namespace std;

struct node{
    string val;
    node* next;
    node* prev;
    node(string val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};


class LinkedL{
    node* head;
    node* tail;

public:
    LinkedL() {
        head=tail=nullptr;
    }

    void push(string s) {
        node* nod = new node(s);
        if(head==nullptr) {
            head=tail=nod;
        }
        else{
            tail->next=nod;
            nod->prev=tail;
            tail=nod;
        }
    }

    void ars() {
        tail->next=head;
        tail=head;
        head=head->next;
        tail->next=nullptr;
    }

    void abs() {
        node* c = head;
        while(c!=nullptr) {
            cout<<c->val<<" ";
            c=c->next;
        }
    }
};
int main() {
    LinkedL ll;
    int n, m;cin>>n>>m;
    for(int i=0;i<n;i++) {
        string x;cin>>x;
        ll.push(x);
    }
    while(m--) {
        ll.ars();
    }
    ll.abs();
}