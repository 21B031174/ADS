#include <iostream>
using namespace std;

struct node
{
    int val;
    node * next;
    node * prev;
    node(int val){
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
    void add(int n){
        node * current = new node(n);
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

    void chek(int n){
        node * current = head;
        int min = 10000;
        int i=0;
        int res;
        while(current!= NULL){
            if(abs(n - current->val)<min){
                min = abs(n - current->val);
                res = i; 
            }
            current = current->next;
            i++;
        }
        cout<<res;
    }
};




int main(){
    int a,b,c;cin>>a;
    LincedL list;
    for(int i=0;i<a;i++){
        cin>>b;
        list.add(b);
    }
    cin>>c;list.chek(c);
    return 0;
}