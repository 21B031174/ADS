#include <iostream>

using namespace std;

struct node{
    int vall;
    node* next;
    node* prev;
    node(int vall){
        this -> vall = vall;
        next = nullptr;
        prev = nullptr;
    }
};

int tem;

class LinkedL{
    node* head;
    node* tail;
    int k;
public:
    LinkedL(){
        k = 0;
        head = nullptr;
        tail = nullptr;
    }
    node * cyclicleft(int n){
        node * c = head;
        while(--n){
            c = c -> next;
        }
        return c;
    }
    void insert(int vall,int n){
        node * nod = new node(vall);
        if(!head){
            head = tail = nod;
            k++;
        }
        else{
            node* need = cyclicleft(n+1);
            if(!need){
                tail -> next = nod;
                nod -> prev = tail;
                tail = nod;
                k++;
            }
            else if (need -> prev){
                need -> prev -> next = nod;
                nod -> prev = need -> prev;
                nod -> next = need;
                need -> prev = nod;
                k++;

            }
            else{
                nod -> next = head;
                head -> prev = nod;
                head = head -> prev;
                k++;
            }
        }
    }
    void erase(int n,int &tem){
        node* need = cyclicleft(n+1);
        tem = need -> vall;
        if(need -> prev && need -> next!= nullptr){ 
            need -> prev -> next = need -> next;
            need -> next -> prev = need -> prev;
            k--;
        }
        else if(need -> prev == nullptr && need -> next == nullptr){ 
            head = tail = nullptr;
            k--;
        }
        else if (need -> next == nullptr){ 
            need -> prev -> next = nullptr;
            tail = need -> prev;
            k--;
        }
        else{   
            head = head -> next;
            head -> prev = nullptr;
            k--;
        }
        

    }
    void replace(int p1,int p2){
        erase(p1,tem);   
        insert(tem,p2);   
    }
    void reverse(){
        node* c = head;
        node* next = nullptr;
        node* prev = nullptr;
        tail = c;
        while(c!=nullptr){
            next = c -> next;
            c -> prev = next;
            c -> next = prev;
            prev = c;
            c = next;
        }
        head = prev;
    }
    void push_back(int vall){
        node* nod = new node(vall);
        if(head==nullptr){
            head = tail = nullptr;
        }
        else{
            tail -> next = nod;
            nod -> prev = tail;
            tail = tail -> next;
        }
    }
    void cyclic_left(int k){
        int cnt=0;
        node * c = head;
        while(c!=nullptr){
            if(cnt == k%ret()){
                head = c;
                return;
            }
            else{
                node* nod = new node(c->vall);
                tail -> next = nod;
                nod -> prev = tail;
                tail = tail -> next;
                head = head -> next;
                head -> prev = nullptr;
            }
            c = c -> next;
            cnt++;
        }
    }
    void cyclic_right(int k){
        int cnt = 0;
        node* c = tail;
        while(c){
            if(cnt == k % ret()){
                tail = c;return;
            }
            else{
                node * nod = new node(c -> vall);
                head -> prev = nod;
                nod -> next = head;
                head = nod;
                tail = tail -> prev;
                tail -> next = nullptr;
            }
            c = c -> prev;
            cnt++;
        }
    }
    int ret(){
        return k;
    }
    void print(){
        node* c = head;
        while(c!=nullptr){
            cout<<c -> vall<<" ";
            c = c -> next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedL dq;
    while(true){
        int n;
        cin>>n;
        if(n==0){
            return 0;
        }
        else if(n==1){
            int x,p;
            cin>>x>>p;
            dq.insert(x,p);
        }
        else if(n==2){
            int p;
            cin>>p;
            dq.erase(p,tem);
        }
        else if(n==3){
            if(dq.ret()!=0)dq.print();
            else cout<<-1<<endl;
        }
        else if(n==4){
            int p1,p2;
            cin>>p1>>p2;
            dq.replace(p1,p2);
        }
        else if(n==5)dq.reverse();
        else if(n==6){
            int x;
            cin>>x;
            dq.cyclicleft(x);
        }
        else if(n==7){
            int x;
            cin>>x;
            dq.cyclic_right(x);
        }
    }
}