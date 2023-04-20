#include <iostream>

using namespace std;

struct node{
    string vall;
    node* next;
    node*prev;
    node(string vall) {
        this->vall=vall;
        next=nullptr;
        prev=nullptr;
    }
};

class LinkedL{
public:
    node* head;
    node* tail;
    int k;
    LinkedL() {
        head=tail=nullptr;
        k=0;
    }

    void add_back(string vall) {
        node* nod = new node(vall);
        if(head==nullptr) {
            head=tail=nod;
        }
        else{
            tail->next=nod;
            nod->prev=tail;
            tail=nod;
        }
        k++;
    }

    void add_front(string vall) {
        node * nod = new node(vall);
        if(head==nullptr) {
            head=tail=nod;
        }
        else{
            head->prev=nod;
            nod->next=head;
            head=nod;
        }
        k++;
    }

    void er_back() {
        cout<<tail->vall<<endl;
        if(tail->prev==nullptr) {
            tail=head=nullptr;
        }
        else{
            tail=tail->prev;
            tail->next->prev=nullptr;
            tail->next=nullptr;
        }
        k--;
    }
    void er_front(){
        cout<<head->vall<<endl;
        if(head->next==nullptr) {
            head=tail=nullptr;
        }
        else{
            head=head->next;
            head->prev->next=nullptr;
            head->prev=nullptr;
        }
        k--;

    }

    void print_front() {
        cout<<head->vall<<endl;
    }
    void print_back() {
        cout<<tail->vall<<endl;
    }
    void clear() {
        head=tail=nullptr;
        k=0;
    }

};

int main() {
    LinkedL ll;
    string s, t;
    while(cin>>s) {
        if(s=="add_front") {
            cin>>t;
            ll.add_front(t);
            cout<<"ok"<<endl;
        }
        if(s=="add_back") {
            cin>>t;
            ll.add_back(t);
            cout<<"ok"<<endl;
        }
        if(s=="front") {
            if(ll.k == 0) cout<<"error"<<endl;
            else ll.print_front();
        }
        if(s=="back") {
            if(ll.k == 0) cout<<"error"<<endl;
            else ll.print_back();
        }
        if(s=="erase_front") {
            if(ll.k == 0) cout<<"error"<<endl;
            else ll.er_front();
        }
        if(s=="erase_back") {
            if(ll.k == 0) cout<<"error"<<endl;
            else ll.er_back();
        }
        if(s=="clear") {
            ll.clear();
            cout<<"ok"<<endl;
        }
        if(s=="exit") {
            cout<<"goodbye"<<endl;
            return 0;
        }
    }
}