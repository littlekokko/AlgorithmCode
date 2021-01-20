#include<iostream>
#include<stdio.h>

using namespace std;

int ans[100][3201];
struct things{
    int v,p,q;
    int num;
};
things a[100];
things f[100][6];

int n,m;

int main(){//·Ö×é±³°ü
    cin >> n >> m;
    n /= 10;
    for( int i = 1; i <= m; i++ ){
        cin >> a[ i ].v >> a[ i ].p >> a[ i ].q;
        a[ i ].p *= a[ i ].v;
        a[ i ].v /= 10;
    }
    int conet = 0;
    for( int i = 1; i <= m; i++ ){
        if( a[ i ].q == 0 ){
            int x = 0;
            things b[2];
            for( int j = 1; j <= m; j++ ){
                if( a[ j ].q == i ){
                    b[ x ].p = a[ j ].p;
                    b[ x ].v = a[ j ].v;
                    x++;
                }
            }
            f[ conet ][ 1 ].p = a[ i ].p;
            f[ conet ][ 1 ].v = a[ i ].v;
            if( x == 0 ){
                f[ conet ][ 0 ].num = 1;
            }
            if( x == 1 ){
                f[ conet ][ 0 ].num = 2;
                f[ conet ][ 2 ].p = a[ i ].p + b[ 0 ].p;
                f[ conet ][ 2 ].v = a[ i ].v + b[ 0 ].v;
            }
            if( x == 2 ){
                f[ conet ][ 0 ].num = 4;
                f[ conet ][ 2 ].p = a[ i ].p + b[ 0 ].p;
                f[ conet ][ 2 ].v = a[ i ].v + b[ 0 ].v;
                f[ conet ][ 3 ].p = a[ i ].p + b[ 1 ].p;
                f[ conet ][ 3 ].v = a[ i ].v + b[ 1 ].v;
                f[ conet ][ 4 ].p = a[ i ].p + b[ 0 ].p + b[ 1 ].p;
                f[ conet ][ 4 ].v = a[ i ].v + b[ 0 ].v + b[ 1 ].v;
            }
            conet++;
        }
    }
    for( int i = 0; i < conet; i++ )
        for( int j = 0; j <= n; j++ )
            ans[ i ][ j ] = -1;
    for( int j = 1; j <= f[ 0 ][ 0 ].num; j++ )
        if( f[ 0 ][ j ].v <= n )
            ans[ 0 ][ f[ 0 ][ j ].v ] = f[ 0 ][ j ].p;
    for( int i = 1; i < conet; i++ ){
        ans[ i - 1 ][ 0 ] = 0;
        for( int k = n; k >= 0; k-- ){
            ans[ i ][ k ] = ans[ i - 1][ k ];
            for( int j = 1; j <= f[ i ][ 0 ].num; j++ ){
                if( k - f[ i ][ j ].v >= 0 )
                    if( ans[ i - 1 ][ k - f[ i ][ j ].v ] >= 0 )
                        ans[ i ][ k ] = max( ans[ i ][ k ], ans[ i - 1 ][ k - f[ i ][ j ].v ] + f[ i ][ j ].p );
            }
        }
    }
    int sum = 0;
    for( int k = 0; k <= n; k++ )
        sum = max( sum , ans[ conet - 1 ][ k ] );
    cout << sum << endl;
    return 0;
}
