#include <iostream>
using namespace std;
struct node{
    int val;
    node * next;
    node * prev;
    node(int val){
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};
class LinkedL{
    node * head;
    node * tail;
public:
    LinkedL(){
        head = NULL;
        tail = NULL;
    }
    void add(int a){
        node * current  = new node(a);
        if(head == NULL){
            head = current;
            tail = current;
        }
        else{
            tail->next = current;
            current-> prev = tail;
            tail = current;
        }
    }
    void print(){
        node * current = head;
        int i=0;
        while (current!=NULL){
            if(i%2==0){
                cout<<current->val<<" ";
            }
            current = current -> next;
            i++;
        }
    }
};
int main(){
    LinkedL ll;
    int a,b;cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        ll.add(b);
    }
    ll.print();
    return 0;
}