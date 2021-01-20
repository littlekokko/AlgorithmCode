#include<iostream>

using namespace std;

int bit[ 10 ] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int ans = 0, n;

int change( int x ){
    int k = 0;
    if( x == 0 ) return 6;
    while( x ){
        k += bit[ x % 10 ];
        x /= 10;
    }
    return k;
}

int main(){
    cin >> n;
    n -= 4;
    for( int i = 0; i <= 1111; i++ )
    for( int j = 0; j <= 1111; j++ ){
        if( change( i ) + change( j ) + change( i + j ) == n ) ans++;
    }
    cout << ans;
    return 0;
}
