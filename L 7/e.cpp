#include <iostream>
#include <vector>
using namespace std;
long long sums(vector <long long> x){
    long long sum=0;
    for(long long i=0;i<x.size();i++){
        sum+=x[i];
    }
    return sum;
}
void merge(vector <vector <long long> > & v , long long l1,long long r1,long long l2,long long r2){
    long long n1 = r1-l1+1;
    vector <vector <long long> > L;
    for(long long i=0;i<n1;i++){
        L.push_back(v[i+l1]);
    }
    long long n2 = r2-l2+1;
    vector <vector <long long> > R;
    for(long long i=0;i<n2;i++)R.push_back(v[i+l2]);
    long long i = l1;
    long long i1 = 0;
    long long i2 = 0;
    while (i1<n1 && i2<n2)
    {
        if(sums(L[i1])<sums(R[i2])){
            v[i] = L[i1++];
        }
        else if(sums(L[i1])==sums(R[i2])){
            for(long long x = 0 ; x<L[i1].size();x++){
                if(L[i1][x]>R[i2][x]){
                    v[i] = L[i1++];
                    break;
                }
                else{
                    v[i] = R[i2++];
                    break;
                }
            }
        }
        else{
            v[i] = R[i2++];
        }
        i++;
    }
    while (i1<n1){
        v[i++] = L[i1++];
    }
    while (i2<n2){
        v[i++] = R[i2++];
    }
}
void msort(vector <vector <long long> > & v,long long l,long long r){
    if(l<r){
        long long m = (l+r)/2;
        msort(v,l,m);
        msort(v,m+1,r);
        merge(v,l,m,m+1,r);
    }
}
int main(){
    vector <vector <long long> > v;
    long long n;cin>>n;
    long long m;cin>>m;
    for(long long i=0;i<n;i+=1){
        vector <long long> ppp;
        for(long long j=0;j<m;j++){
            long long z;cin>>z;
            ppp.push_back(z);
        }
        v.push_back(ppp);
    }
    msort(v,0,n-1);
    for(long long i=n-1;i>=0;i-=1){
        for(long long j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}