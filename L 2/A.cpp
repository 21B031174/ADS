#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
    node * prev;

    node(int val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};


class LinkedL{
    node * head;
    node* tail;
public:
    LinkedL() {
        head=nullptr;
        tail=nullptr;
    }
    void add(int val) {
        node * newnode = new node(val);
        if(head==nullptr) {
            head=newnode;
            tail=newnode;
        }
        else {
            tail->next=newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    void ars(int target) {
        node * c = head;
        int result = 100000;
        int i=0;
        int res;
        while(c!=nullptr) {
            if(abs(target-c->val)<result) {
                result=abs(target-c->val);
                res = i;
            }
            c=c->next;
            i++;
        }
        cout<<res;
    }
};


int main() {
    LinkedL list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        list.add(x);
    }
    int t;
    cin>>t;
    list.ars(t);
    
}