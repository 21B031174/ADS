#include <iostream>

using namespace std;

struct node{
    string val;
    int cnt=1;
    node * next;
    node * prev;
    node(string val){
        this->val = val;
        this->next = this->prev = NULL;
    }
};

class LincedL{
    node * head;
    node * tail;
    int max=0;
public:
    LincedL(){
        head = tail = NULL;
    }
    void add(string s){
        node * current = new node(s);
        if(head == NULL){
            head = current;
            tail = current;
            max=1;
        }
        else{
            if(head->val==s) {
                head->cnt++; 
            }
            else if(head->prev==nullptr) {
                head->prev=current;
                current->next=head;
                head=current;
                max++;
            }
        }
    }
    void print(){
        node * current = tail;
        cout<<"All in all: "<<max<<endl<<"Students:"<<endl;
        while (current!=NULL)
        {
            cout<<current->val<<endl;
            current = current->prev;
        }
    }
};




int main(){
    LincedL ll;
    int a;cin>>a;
    string s;
    for(int i=0;i<a;i++){
        cin>>s;
        ll.add(s);
    }
    ll.print();
    return 0;
}