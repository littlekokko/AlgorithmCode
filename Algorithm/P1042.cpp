#include<iostream>
#include<stdio.h>

using namespace std;

bool prime( int x ){
    for( int i = 2; i * i <= x; i++ )
        if( x % i == 0 ) return false;
    return true;
}

bool hw( int x ){
    int k = x;
    int l = 0;
    int num[ 20 ];
    while( k > 0){
        num[ l++ ] = k % 10;
        k /= 10;
    }
    for( int i = 0; i < l; i++ )
        if( num[ i ] != num[ l - i - 1 ] )
            return false;
    return true;
}

int main(){
    int m,n;
    cin >> m >> n;
    n = min( n , 10000000 );//偶数位的回文数会被11整除
    for( int i = m; i <= n; i++ )
        if( hw( i ) )
            if( prime( i ) )
                cout << i << endl;
    return 0;
}
