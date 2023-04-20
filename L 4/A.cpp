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
    void check(string s){
        this->check(this->root,s);
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
    void check(node * current,string s,int i=0){
        if(s.size()!=i){
            if(s[i]=='L'){
                if(current != NULL){
                    check(current->left,s,i+1);
                }
                else{
                    check(current,s,s.size());
                }
            }
            else if(s[i]=='R'){
                if(current != NULL){
                    check(current->right,s,i+1);
                }
                else{ 
                    check(current,s,s.size());
                }
            }
        }
        else{
            if(current != NULL){
                cout<<"YES"<<endl;
                return;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    // void print(node * current){
    //     if(current != NULL){
    //         print(current->left);
    //         cout << current->val << " ";
    //         print(current->right);
    //     }
    // }
};
int main(){
    int a;cin>>a;
    int p;cin>>p;
    int arr1[a];
    bst * b = new bst();
    for(int i = 0; i < a; i++){
        cin>>arr1[i];
        b->add(arr1[i]);
    }
    string st;
    for(int i=0;i<p;i++){
        cin>>st;
        b->check(st);
    }
    return 0;
}
