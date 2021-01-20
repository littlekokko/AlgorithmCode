#include<iostream>
#include<stdio.h>

using namespace std;

int n, sum, ans, p;
int num[ 110 ];

int main(){
    cin >> n;
    sum = 0;
    for( int i = 0; i < n; i++ ){
        cin >> num[ i ];
        sum += num[ i ];
    }
    p = sum / n;
    ans = 0;
    for( int i = 0; i < n; i++ ){
        if( p != num[ i ] ){
            ans++;
            int t = p - num[ i ];
            num[ i ] = p;
            num[ i + 1 ] -= t;
        }
    }
    cout << ans << endl;
    return 0;
}
