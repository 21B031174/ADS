#include <iostream>

using namespace std;

struct node{
    char vall;
    node * next;
    node(char vall) {
        this->vall = vall;
        next=nullptr;
    }
};

class LinkedL{
public:
    int arr[26];
    node * head;
    LinkedL() {
        for (int i = 0; i < 26; i ++) {
            arr[i] = 0;
        }
        head=nullptr;
    }
    void add(char vall) {
        node * nod = new node(vall);
        if(head==nullptr) {
            cout << vall << " ";
            arr[vall - 'a']++;
            head=nod;
        }
        else{
            node * c = head;
            char res = '!';
            arr[vall - 'a']++;
            bool ok = false;
            while(c!=nullptr){
                if (arr[c -> vall - 'a'] == 1 && !ok){
                    ok = 1;
                    res = c -> vall;
                }
                if(c->next==nullptr) {
                    if (arr[vall - 'a'] == 1 && !ok) res = vall;
                    c->next=nod;
                    break;
                }
                c=c->next;
            }
            if (res == '!') cout << -1 << " ";
            else cout << res << " ";
        }

    }
};

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        LinkedL ll;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            ll.add(x);
        }
        cout<<endl;
    }
}