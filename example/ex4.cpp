#include <iostream>

using namespace std;

struct node{
    int val;
    int cnt=1;
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
        else{//     1 2 2 9 8 9 6 6 7 6
        // 9 2 1
            node * cur = head;
            while (cur!=NULL)
            {
                if(cur->val==a){
                    current->cnt++;
                }
                else if(cur->val > a){
                    cur->prev = current;
                }
                else{
                    cur->next = current;
                    
                }
                cur=cur->next;
            }
            
            
            if(tail->val)
            tail->next = current;
            current-> prev = tail;
            tail = current;
        }
    }
    void print(){
        node * current = head;
        int i=0;
        int res;
        while (current!=NULL){
            if(i<current->cnt){
                i=current->cnt;
            }
            current = current -> next;
        }
        while (current!=NULL){
            if(i==current->cnt){
                cout<<current->val<<" ";
            }
            current = current -> next; 
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




