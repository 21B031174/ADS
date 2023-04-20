#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt=1;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst{
    public:
    
    bst(){
        root = NULL;
    }

    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }


    void print(int a){
        this->print(this->root,a);
    }


    void del(int a){
        this->del(this->root,a);
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
        else if(current->val == x){
            current->cnt++;
        }
        return current;
    }

    void del(node * current,int a){
        if(current!= NULL){
            if(current->val > a){
                del(current->left, a);
            }
            else if(current->val <a){
                del(current->right, a);
            }
            else{
                current->cnt--;
            }
        }
    }

    void print(node * current, int a){
        if(current!= NULL){
            if(current->val > a){
                print(current->left, a);
            }
            else if(current->val <a){
                print(current->right, a);
            }
            else{
                cout<<current->cnt<<endl;
            }
        }
        else{
            cout<<"0"<<endl;
        }
    }
};


int main(){
    int a;cin>>a;
    int p;
    string s;
    bst * b = new bst();
    for(int i = 0; i < a; i++){
        cin>>s>>p;
        if(s=="insert"){
            b->add(p);
        }
        else if(s=="cnt"){
            b->print(p);
        }
        else if(s=="delete"){
            b->del(p);
        }
    }

    return 0;
}
