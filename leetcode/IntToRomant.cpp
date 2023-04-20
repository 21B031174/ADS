#include <iostream>
using namespace std;
string intToRoman(int sum){
    string str="";
    int M=sum/1000;
    sum-=M*1000;
    for(int i=0;i<M;i++){
        str+="M";
    }
    int C=sum/100;
    sum-=C*100;
    if(C==9)str+="CM";
    else if(C>4){
        str+="D";
        for(int i=0;i<C-5;i++){
            str+="C";
        }
    }
    else if(C==4)str+="CD";
    else if(C<4){
        for(int i=0;i<C;i++){
            str+="C";
        }
    }
    int X=sum/10;
    sum-=X*10;
    if(X==9)str+="XC";
    else if(X>4){
        str+="L";
        for(int i=0;i<X-5;i++){
            str+="X";
        }
    }
    else if(X==4)str+="XL";
    else if(X<4){
        for(int i=0;i<X;i++){
            str+="X";
        }
    }
    int I=sum/1;
    sum-=I*1;
    if(I==9)str+="IX";
    else if(I>4){
        str+="V";
        for(int i=0;i<I-5;i++){
            str+="I";
        }
    }
    else if(I==4)str+="IV";
    else if(I<4){
        for(int i=0;i<I;i++){
            str+="I";
        }
    }
    return str;
}

int main(){
    int a;cin>>a;
    cout<<intToRoman(a).substr(1);
    return 0;
}