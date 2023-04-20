#include <iostream>
#include <vector>

using namespace std;
int arr[5000]={0};


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
    void print(){
        this->print(this->root);
    }
    int maximum(){
        return max;
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
    int i=0;
    
    void print(node * current){
        if(current != NULL){
            i++;
            print(current->left);
            i--;
            if(max<i){
                max=i;
            }
            arr[i]+=current->val;
            i++;
            print(current->right);
            i--;
        }
        
    }
};
int main(){
    int a,z;cin>>a;
    int n = sizeof(arr)/sizeof(int);
    bst * b = new bst();
    for(int i = 0; i < a; i++){
        cin>>z;
        b->add(z);
    }
    b->print();
    cout<<b->maximum()+1<<endl;
    for(int i = 0; i < n; i++){
        if(arr[i]==0){break;}
        cout<<arr[i]<<" ";
    }
    return 0;
}


//        5
//     3       8
//   2  4   7    9
// 1       6       10