#include <iostream>

using namespace std;

struct node {
    int vall;
    int index;
    node * next;
    node * prev;
    node(int vall) {
        this->vall=vall;
        next=nullptr;
        prev=nullptr;
    }
};
class LinkedL{
    node * head;
    node * tail;
public:
    LinkedL() {
        head=tail=nullptr;
    }
    void add(int vall) {
        node * nod = new node(vall);
        if(head==nullptr) {
            head=nod;
            tail=nod;
        }
        else {
            tail->next=nod;
            nod->prev=tail;
            tail=nod;
        }
    }
    void insert(int k, int vall) {
        node * nod=new node(vall);
        int i=1;
        if(head==nullptr)head=nod;
        else{
            node * c = head;
            while(c!=nullptr) {
                if(k==0) {
                    head->prev=nod;
                    nod->next=head;
                    head=nod;
                    break;
                }
                else if(i==k) {
                    nod->next=c->next;
                    c->next=nod;
                    break;
                }
                c=c->next;
                i++;
            }
        }
    }
    void print() {
        node * c =head;
        while(c!=nullptr) {
            cout<<c->vall<<" ";
            c=c->next;
        }
    }
};
int main() {
    LinkedL ll;
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        ll.add(x);
    }
    int a, k;
    cin>>a>>k;
    ll.insert(k, a);
    ll.print();
}