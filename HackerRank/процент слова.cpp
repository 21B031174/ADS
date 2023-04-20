#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <string> 
#include <map> 
#define m_p make_pair 
#define f_l for(int i=0;i<n;i++) 
#define f_j for(int j=0;j<n;j++) 
#define p_b push_back 
#define it map <string ,double>::iterator 
using namespace std; 
bool fun(pair<string, double > a,pair<string, double > b){ 
    if(a.second>b.second)return true; 
    return false; 
} 
int main(){ 
    string str; 
    map <string ,double> arr; 
    vector <pair<string , double> > arr2; 
    double cnt=0; 
    freopen("input.txt","r",stdin); 
    while (cin>>str) 
    { 
        cnt++; 
        for(int i=0;i<str.size();i++){ 
            str[i]=towlower(str[i]); 
        } 
        arr[str]+=1; 
    } 
     
 
    it iter; 
    for(iter = arr.begin();iter!=arr.end();iter++){ 
        arr2.p_b(m_p((*iter).first,(*iter).second)); 
    } 
    sort(arr2.begin(),arr2.end(),fun); 
 
 
    for(int i=0;i<arr2.size();i++){ 
        cout<<arr2[i].first<<" : "<<arr2[i].second*(100/cnt)<<"%"<<"\n"; 
    } 
 
}