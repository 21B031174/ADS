#include <iostream>

using namespace std;

struct node{
    int vall;
    node * prev;
    node * next;
    node(int vall) {
        this->vall=vall;
        next=nullptr;
        prev=nullptr;
    }
};

class LinkedL{
public:
    node * head;
    node * tail;
    int res, m;
    LinkedL() {
        head=tail=nullptr;
        res=-1000000;
        m=0;
    }
    void add(int vall) {
        node * nod = new node(vall);
        if(head==nullptr) {
            head=tail=nod;
        }
        else {    
            tail->next=nod;
            nod->prev=tail;
            tail=nod;
        }
    }
    void subarray() {
        node * cur = head;
        while(cur!=nullptr) {
            m+=cur->vall;
            if(m<cur->vall){
                m=cur->vall;
            }
            res=max(m, res);
            cur=cur->next;
        }
        cout<<res<<endl;
    }
};
int main() {
    LinkedL ll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        ll.add(x);
    }
    ll.subarray();
}