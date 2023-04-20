#include <iostream>
using namespace std;
struct node{
    int val;
    node(int x){
        val = x;
    }
    node *next;
};
struct LinkedL{
    node * head;
    node * tail;
    LinkedL(){
        head = NULL;
        tail = NULL;
    }
    void add_back(int x){
        node * nod = new node(x);
        if(head == NULL ){
            head = nod;
            tail = nod;
        }
        else{
            tail -> next = nod;
            tail = nod;
        }
    } 
    void print(){
        node * curva = head;
        while(curva!=NULL){
            cout<<curva->val<<" ";
            curva = curva->next;
        }
    }  
};

int main(){
    int n;cin>>n;
    LinkedL ll;
    for(int i=0;i<n;i+=1){
        int z;cin>>z;
        ll.add_back(z);
    }
    ll.print();
    return 0;
}