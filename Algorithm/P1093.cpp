#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int a=1,b=1,c=1;
    int n;
    int k = 7654321;
    cin >> n;
    for(int i = 3; i <= n; i++ ){
        c = a + b;
        a = b % k;
        b = c % k;
    }
    c %= k;
    cout << c << endl;
    return 0;
}
