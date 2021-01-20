#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
long long a[ 500001 ], t[ 500001 ], n, T;

int get( int x, long long dlt){
    long long l,r;
    l = ( ( x - dlt ) % ( n * 2 ) + n * 2 - 1 ) % ( n * 2 ) + 1;
    r = ( ( x + dlt ) - 1 ) % ( n * 2 ) + 1;
    if( !a[ l ] )
        return 0;
    if( a[ l ] == a[ r ] )
        return 1;
    else
        return 2;
}

void ksm(long long x, long long dlt){
    if( x == 0 )
        return;
    ksm( x >> 1 , dlt << 1 );
    if( x & 1 ){
        for( int i = 1; i <= 2 * n; i++ ){
            t[ i ] = get( i, dlt );
        }
        for( int i = 1; i <= 2 * n; i++ )
            a[ i ] = t[ i ];
    }
}

int main(){
    scanf( "%lld%lld", &n, &T );
    for( int i = 1; i <= n; i++ )
        scanf( "%lld", &a[ 2 * i - 1 ] );
    ksm( T, 1 );
    for( int i = 1; i <= 2 * n; i++ )
        printf( "%lld ", a[ i ] );
}
