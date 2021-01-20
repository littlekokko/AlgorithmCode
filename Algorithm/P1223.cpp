#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int p, ans, a[ 1000 ], b[ 500 ];
void work(int n){
    if( !n ) return;
    work( n >> 1 );
    for( int i = 0; i < 500; i++ )
        for( int j = 0; j < 500; j++ )
            if( n & 1 )
                a[ i + j ] = a[ i + j ] + b[ i ] * b[ j ] * 2;
            else
                a[ i + j ] = a[ i + j ] + b[ i ] * b[ j ];
    for( int i = 0; i < 500; i++ ) {
        b[ i ] = a[ i ] % 10;
        a[ i + 1 ] = a[ i + 1 ] + a[ i ] / 10 ;
    }
    memset( a, 0, sizeof( a ) );
}

int main(){
    scanf( "%d", &p );
    b[ 0 ] = 1;
    work( p );
    ans = int( ( log( 2 ) / log( 10 ) ) * p + 1 );
    cout << ans << endl;
    for( int i = 500 - 1; i > 0; i-- ) {
        cout << b[ i ];
        if( !( i % 50 ) ) cout << endl;
    }
    cout << b[ 0 ] - 1 << endl;
    return 0;
}
