#include <iostream>

using namespace std;

string numberToWords(int num){
    if(num==0)return "Zero";
    string str="";
    string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};

    int B=num/1000000000;
    num-=B*1000000000;
    if(B>0){
        if(B>=100){
            int k=B/100;
            B-=k*100;
            str+=ones[k]+" Hundred";
        }
        if(B>=20){
            int k=B/10;
            B-=k*10;
            str+=tens[k]+ones[B]+thousands[3];
        }
        else str+=ones[B]+thousands[3];
    }
    
    int M=num/1000000;
    num-=M*1000000;
    if(M>0){
        if(M>=100){
            int k=M/100;
            M-=k*100;
            str+=ones[k]+" Hundred";
        }
        if(M>=20){
            int k=M/10;
            M-=k*10;
            str+=tens[k]+ones[M]+thousands[2];
        }
        else str+=ones[M]+thousands[2];
    }
    
    int T=num/1000;
    num-=T*1000;
    if(T>0){
        if(T>=100){
            int k=T/100;
            T-=k*100;
            str+=ones[k]+" Hundred";
        }
        if(T>=20){
            int k=T/10;
            T-=k*10;
            str+=tens[k]+ones[T]+thousands[1];
        }
        else str+=ones[T]+thousands[1];
    }
    
    if(num/100>0){
        int k=num/100;
        num-=k*100;
        str+=ones[k]+" Hundred";
    }
    if(num>=20){
        int k=num/10;
        num-=k*10;
        str+=tens[k]+ones[num];
    }
    else str+=ones[num];
    return str;
}


int main(){
    int a;cin>>a;
    cout<<numberToWords(a);
}