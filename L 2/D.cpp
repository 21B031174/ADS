#include <iostream>

using namespace std;

struct node{
    int vall;
    node* next;
    node* tail;
    int cnt;
    node(int vall) {
        this->vall=vall;
        cnt=1;
        next=nullptr;
        tail=nullptr;
    }
};

class LincedL{
    node* head;
    int max=-1000000;
public:
    LincedL() {
        head=nullptr;
    }
    void add(int vall) {
        node* nod = new node(vall);

        if(head==nullptr) {
            head=nod;
        }
        else{
            node * c = head;
            while(c!=nullptr) {
                if(c->vall == vall) {
                    c->cnt++;
                    break;
                }
                if(c->next==nullptr) {
                    c->next=nod;
                    break;
                }
                c=c->next;
            }
        }
    }
    void maximim() {
        node * c = head;
        while(c!=nullptr) {
            if(c->cnt>max) max=c->cnt;
            c=c->next;
        }
    }
    void sorted() {
        node * a = head;
        node * b = nullptr;
        while(a!=nullptr) {
            b=a->next;
             while(b!=nullptr) {
                if(a->vall < b->vall) {
                    swap(a->vall, b->vall);
                    swap(a->cnt, b->cnt);
                }
                if(a->cnt > b->cnt){
                    swap(a->vall, b->vall);
                    swap(a->cnt, b->cnt);
                }
                b=b->next;
            }
            a=a->next;
        }
    }

    void print() {
        node * c = head;
        while(c!=nullptr) {
            sorted();
            if(c->cnt==max) cout<<c->vall<<" ";
            c=c->next;
        }
    }

};

int main() {
    LincedL ll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        ll.add(x);
    }
    ll.maximim();
    ll.print();
}