#include <iostream>
#include <vector>

using namespace std;

int partition(vector<char> & a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(int(a[j]) < int(a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(vector<char> & a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    int n;cin>>n;
    char c;
    vector<char> v1;
    vector<char> v2;

    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='a' || c=='e' || c=='i' || c=='u' || c=='o')v1.push_back(c);
        else v2.push_back(c);
    }
    qsort(v1, 0, v1.size() - 1);
    qsort(v2, 0, v2.size() - 1);

    for(int i = 0; i < v1.size(); ++i){
        cout << v1[i];
    }

    for(int i = 0; i < v2.size(); ++i){
        cout << v2[i];
    }
    return 0;
}