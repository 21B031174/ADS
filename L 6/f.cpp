#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath>
using namespace std;
string arr[1000000][2];
int partition(double * a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
            swap(arr[i], arr[j]);
        }
        else if(a[j] == a[pivot]){
            if(arr[j][0] < arr[pivot][0]){
                i++;
                swap(a[i], a[j]);
                swap(arr[i], arr[j]);
            }
            else if(arr[j][0] == arr[pivot][0]){
                if(arr[j][1] < arr[pivot][1]){
                    i++;
                    swap(a[i], a[j]);
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    swap(a[i + 1], a[pivot]);
    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}


void qsort(double * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
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
    qsort(gpa, 0, a - 1);
    
    for(int i = 0; i < a; ++i){
        cout << arr[i][0]<< " " <<arr[i][1] << " ";
        cout << fixed << setprecision(3) << gpa[i] << "\n";
    }

    return 0;
}