#include<iostream>
#include<stdio.h>

using namespace std;

long long n;
long long ans;

int main(){
    cin >> n;
    ans = ( n * ( n + 1 ) * ( 2 * n + 1 ) ) / 6;
    cout << ans << endl;
    return 0;
}
