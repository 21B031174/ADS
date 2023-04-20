#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst{
    public:
    int cnt=0;
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }
    int pp(){
        return cnt;
    }
    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }
        else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }
        else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
        }
        return current;
    }
    
    void print(node * current){
        if(current != NULL){
            if(current->left!=NULL && current->right!=NULL){
                cnt++;
            }
            print(current->left);
            
            print(current->right);
        }
    }
};
int main(){
    int a;cin>>a;
    int p;
    bst * b = new bst();
    for(int i = 0; i < a; i++){
        cin>>p;
        b->add(p);
    }
    b->print();
    cout<<b->pp();
    return 0;
}
