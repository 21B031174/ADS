#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath>
using namespace std;
string arr[1000000][2];

void merge(double * a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    double L[n1];
    string sl[n1][2];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
        sl[i][0] = arr[l1 + i][0];
        sl[i][1] = arr[l1 + i][1];
    }

    int n2 = r2 - l2 + 1;
    double R[n2];
    string sr[n2][2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
        sr[i][0] = arr[l2 + i][0];
        sr[i][1] = arr[l2 + i][1];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]){
            a[i] = L[i1];
            arr[i][0]=sl[i1][0];
            arr[i][1]=sl[i1][1];
            i++;
            i1++;
        }else if(L[i1] == R[i2]){
            if(sl[i1][0]<sr[i2][0]){
                a[i] = L[i1];
                arr[i][0]=sl[i1][0];
                arr[i][1]=sl[i1][1];
                i++;
                i1++;
            }
            else if(sl[i1][0]==sr[i2][0]){
                if(sl[i1][1]<sr[i2][1]){
                    a[i] = L[i1];
                    arr[i][0]=sl[i1][0];
                    arr[i][1]=sl[i1][1];
                    i++;
                    i1++;
                }
                else{
                    a[i] = R[i2];
                    arr[i][0]=sr[i2][0];
                    arr[i][1]=sr[i2][1];
                    i++;
                    i2++;
                }
            }
            else{
                a[i] = R[i2];
                arr[i][0]=sr[i2][0];
                arr[i][1]=sr[i2][1];
                i++;
                i2++;
            }
        }
        else{
            a[i] = R[i2];
            arr[i][0]=sr[i2][0];
            arr[i][1]=sr[i2][1];
            i++;
            i2++;
        }
    }
    while(i1 < n1){
        a[i] = L[i1];
        arr[i][0]=sl[i1][0];
        arr[i][1]=sl[i1][1];
        i++;
        i1++;
    }
    while(i2 < n2){
        a[i] = R[i2];
        arr[i][0]=sr[i2][0];
        arr[i][1]=sr[i2][1];
        i++;
        i2++;
    }
}

void msort(double * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

double GPA(string a){
    if(a=="A+")return 4.00;
    if(a=="A")return 3.75;
    if(a=="B+")return 3.50;
    if(a=="B")return 3.00;
    if(a=="C+")return 2.50;
    if(a=="C")return 2.00;
    if(a=="D+")return 1.50;
    if(a=="D")return 1.00;
    if(a=="F")return 0.00;
}

int main(){

    int a,n,m;cin>>a;
    double gpa[a];
    
    for(int i=0;i<a;i++){
        double sum=0;
        int cnt=0;
        cin>>arr[i][0]>>arr[i][1]>>n;
        for(int j=0;j<n;j++){
            string ch;cin>>ch>>m;
            double p = GPA(ch);
            sum+=p*m;
            cnt+=m;
        }
        gpa[i] = sum/cnt;
    }
    msort(gpa, 0, a - 1);
    
    for(int i = 0; i < a; ++i){
        cout << arr[i][0]<< " " <<arr[i][1] << " ";
        cout << fixed << setprecision(3) << gpa[i] << "\n";
    }

    return 0;
}