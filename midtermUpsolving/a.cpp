#include <iostream>
using namespace std;
int arr[100000];
struct node{
    int val;
    node * right;
    node * left;
    node(int x){
        val = x;
        left = right = NULL;
    }
};



struct bst{
    node * root;
    bst(){
        root = NULL;
    }
    void add(int x){
        node * n = new node(x);
        if(root == NULL){
            root = n;
        }
        else{
            node * current = root;
            while (true)
            {
                if(current->val<x){
                    if(current->right!=NULL){
                        current=current->right;
                    }
                    else{
                        current->right=n;
                        return;
                    }
                }
                else{
                    if(current->left!=NULL){
                        current=current->left;
                    }
                    else{
                        current->left=n;
                        return;
                    }
                }
            }   
        }
    }
    void print(){
        node * cur = root;
        printing(cur);
    }
    void printing(node * cur){
        if(cur!=NULL){
            printing(cur->left);
            cout<<cur->val<<" ";
            printing(cur->right);
        }
    }


    void answer(int n){
        node * cur = root;
        ll(n,cur);
    }
    void ll(int n,node * cur){
        if(cur!=NULL){
            ll(n,cur->left);
            chek(cur,n);
            ll(n,cur->right);
        }
    }
    void chek(node * cur,int n){
        node * currentL = cur;
        node * currentR = cur;
        for(int i=1;i<=n;i+=1){
            if(currentL->left!=NULL and currentR->right!=NULL){
                arr[i]++;
                currentL=currentL->left;
                currentR=currentR->right;
            }
            else{
                return;
            }
        }
    }
};

int main(){
    int n;cin>>n;
    bst b;
    for(int i=0;i<n;i+=1){
        int z;cin>>z;
        b.add(z);
    }
    b.answer(n-1);
    for(int i=1;i<=n-1;i+=1){
        cout<<arr[i]<<" ";
    }
    return 0;
}