#include<iostream>
#include<stdio.h>

using namespace std;

long long ans, a, b;

int main(){//a^b������
    cin >> a >> b;
    ans = 1
    do b&1?ans*=a,a*=a:a*=a; while(b>>=1);
    cout << ans << endl;
    return 0;
}
