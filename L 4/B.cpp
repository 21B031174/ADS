
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
    int max=0;
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    // void print(){
    //     this->print(this->root);
    // }
    void check(int s){
        this->check(this->root,s);
    }
    void maximum(){
        cout<<max;
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
    void check(node * current, int a){
        if(current!= NULL){
            if(current->val > a){
                check(current->left, a);
            }
            else if(current->val <a){
                check(current->right, a);
            }
            else{
                print(current);
            }
        }
    }

    void print(node * current){
        if(current != NULL){
            print(current->left);
            max++;
            print(current->right);
        }
    }
};
int main(){
    int a;cin>>a;
    
    int k;
    bst * b = new bst();
    for(int i = 0; i < a; i++){
        cin>>k;
        b->add(k);
    }
    int p;cin>>p;
    b->check(p);
    b->maximum();
    return 0;
}


//          4
//       2     6
//     1   3  5  7