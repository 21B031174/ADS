#include <iostream>

using namespace std;

struct node{
    string val;
    node * next;
    node * prev;
    node(string val){
        this->val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class LincedL{
    node * head;
    node* tail;

public:
    LincedL(){
        head = NULL;
        tail = NULL;
    }
    void add(string s){
        node * current  = new node(s);
        if(head == NULL){
            head = current;
            tail = current;
        }
        else{
            tail -> next = current;
            // current ->prev = tail;
            tail = current;
        }
    }
    void print1(int a){
        node * current = head;
        node * cur = head;
        int i=0;
        while(current!= NULL){
            if(i>=a){
                cout<<current->val<<" ";
            }
            current = current->next;
            i++;
        }
        i=0;
        while (cur!=NULL)
        {
            if(i<a){
                cout<<cur->val<<" ";
            }
            cur = cur->next;
            i++;
        }
        
    }
};

int main(){
    LincedL list;
    int a,b;cin>>a>>b;
    for(int i=0;i<a;i++){
        string s;cin>>s;
        list.add(s);
    }
    list.print1(b);
    
}