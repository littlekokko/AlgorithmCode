#include<iostream>
#include<stdio.h>

using namespace std;

int num[ 40 ];
int n;
int f[ 40 ][ 40 ];
int g[ 40 ][ 40 ];

void work( int x, int y ){
    if( x > y ) return;
    if( x == y ){
        printf( "%d ", x );
    }
    else{
        int q = g[ x ][ y ];
        printf( "%d ", q );
        work( x, q - 1 );
        work( q + 1, y );
    }
}

int main(){
    scanf( "%d", &n );
    for( int i = 1; i <= n; i++ ){
        scanf( "%d", &num[ i ] );
        f[ i ][ i ] = num[ i ];
    }
    for( int l = 2; l <= n; l++ ){
        for( int i = 1; i <= ( n - l + 1); i++ ){
            int j = i + l - 1;
            int p;
            f[ i ][ j ] = f[ i + 1 ][ j ] + num[ i ];
            g[ i ][ j ] = i;
            for( int k = i + 1; k < j; k++ ){
                p = f[ i ][ k - 1 ] * f[ k + 1 ][ j ] + num[ k ];
                if( p > f[ i ][ j ] ){
                    f[ i ][ j ] = p;
                    g[ i ][ j ] = k;
                }
            }
            p = f[ i ][ j - 1 ] + num[ j ];
            if( p > f[ i ][ j ] ){
                f[ i ][ j ] = p;
                g[ i ][ j ] = j;
            }
        }
    }
    printf( "%d\n", f[ 1 ][ n ] );
    work( 1, n );
    printf( "\n" );
    return 0;
}
