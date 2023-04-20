#include <iostream>

using namespace std;

int f(string str1, string str2, string chek)
{
    int cnt = 0;

    int n = str1.size();
    int m = chek.size();

    long long q = 10000007;
    long long power = 1;

    long long txt1 = 0, txt2 = 0, c = 0;

    for (int i = 0; i < m - 1; i++){
        power=(power*17)%q;
    }
    for (int i = 0; i < m; i++){
        txt1 = (((int(str1[i])-96)+(17*txt1)) % q) % q;
        txt2 = (((int(str2[i])-96)+(17*txt2)) % q) % q;
        c = (((int(chek[i])-96)+(17*c)) % q) % q;
    }
    for (int i = 0; i < n - m + 1; i++){
        if (txt1 == c && c == txt2)cnt++;
        if (i!=n-m){
            txt1 = ((txt1-(int(str1[i])-96)*power)*17+(int(str1[i+m])-96))%q;
            txt2 = ((txt2-(int(str2[i])-96)*power)*17+(int(str2[i+m])-96))%q;
            if(txt1<0)txt1+=q;
            if(txt2<0)txt2+=q;
        }
    }
    return cnt;
}

int main()
{
    string str1, str2, chek;
    cin >> str1 >> str2 >> chek;
    cout << f(str1, str2, chek);
}