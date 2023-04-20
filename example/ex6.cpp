#include <iostream> 
using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class LincedL{
    node * head;
    node * tail;
public:
    LincedL(){
        head = tail = NULL;
    }
    void add(int a){
        node * current = new node(a);
        if(head == NULL){
            head = tail = current;
        }
        else{
            tail->next = current;
            current->prev = tail;
            tail = current;
        }
    }
    void create(int data,int pos){
        node * current = head;
        int i=1;
        
        while (current!=NULL)
        {   if(pos==0){
                node * cur = new node(data);
                head ->prev = cur;
                cur -> next = head;
                head = cur;
                return;
            }
            else if(i==pos){
                node * cur = new node(data);
                node * p = current->next;
                current -> next = cur;
                cur ->next = p;
                return ;
            }
            i++;
            current=current->next;
        }
        
    }
    void print(){
        node * current = head;
        while (current!=NULL)
        {
            cout<<current->val<<" ";
            current = current ->next;
        }
    }
};


int main(){
    LincedL ll;
    int a,b,c,d;cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        ll.add(b);
    }
    cin>>c>>d;
    ll.create(c,d);
    ll.print();
    return 0;
}