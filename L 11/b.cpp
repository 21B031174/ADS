#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int one, two, three;
    node(int one, int two, int three){
        this->one = one;
        this->two = two;
        this->three = three;
    }
};

bool comparison(node a, node b){
    return a.three < b.three;
}

int chek(int one, vector <int> &vec){
    if(one != vec[one]) return vec[one] = chek(vec[one], vec);
    else return one;
}

void edit(int one, int two, vector <int> &vec, vector <int> &vec2){
    two = chek(two, vec);
    one = chek(one, vec);
    if(vec2[two] < vec2[one]){
        vec[two] = one;
    }
    else if(vec2[one] < vec2[two]){
        vec[one] = two;
    }
    else{
        vec[two] = one;
        vec2[one]++;
    }
}

int main(){
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    vector<node> nodeVec;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            nodeVec.push_back(node(j, i, a[i] + a[j]));
            nodeVec.push_back(node(i, j, a[i] + a[j]));
        }
    }

    sort(nodeVec.begin(), nodeVec.end(), comparison);

    N = N*N;

    vector <int> vec(N);

    for(int i = 0; i < N; i++){
        vec[i] = i;
    }
    vector <int> vec2(N, 0);
    int sum = 0;

    vector <pair <int, int> > pair;
    for(int i=0;i<nodeVec.size();i++){
        if(!(chek(nodeVec[i].two, vec) == chek(nodeVec[i].one, vec))){
            sum += nodeVec[i].three;
            pair.push_back(make_pair(nodeVec[i].one, nodeVec[i].two));
            edit(nodeVec[i].one, nodeVec[i].two, vec, vec2);
        }
    }
    cout<<sum;
 
 return 0;
}