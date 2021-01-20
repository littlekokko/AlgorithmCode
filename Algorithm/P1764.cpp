#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n,m,a,b;
int num[1050][1050];
int sum[1050][1050];
int f[2][1050];
const int INF = 1000000000;

int getsum( int x1, int y1, int x2, int y2 ){
    return sum[ x1 - 1 ][ y1 - 1 ] + sum[ x2 ][ y2 ] - sum[ x1 - 1 ][ y2 ] - sum[ x2 ][ y1 - 1 ];
}

int main(){
    scanf( "%d%d%d%d" , &n, &m, &a, &b );
    for( int i = 0; i <= max( n , m ) ; i++ )
            f[ 0 ][ i ] = f[ 1 ][ i ] =  -INF;
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ ){
            scanf( "%d" , &num[ i ][ j ]);
            sum[ i ][ j ] = num[ i ][ j ] + sum[ i ][ j - 1 ] + sum[ i - 1 ][ j ] - sum[ i - 1 ][ j - 1 ];
        }

    for( int i = n - 1; i >= 1; i-- ){
        if( i < n - 1 )
            f[ 0 ][ i ] = f[ 0 ][ i + 1 ];
        if( i + a <= n)
            for( int j = 1; ( j + b - 1 ) <= m; j++ )
                f[ 0 ][ i ] = max( f[ 0 ][ i ], getsum( i + 1, j, i + a, j + b - 1 ) );
        if( i + b <= n)
            for( int j = 1; ( j + a - 1 ) <= m; j++ )
                f[ 0 ][ i ] = max( f[ 0 ][ i ], getsum( i + 1, j, i + b, j + a - 1 ) );
    }
    for( int j = m - 1; j >= 1; j-- ){
        if( j < m - 1 )
            f[ 1 ][ j ] = f[ 1 ][ j + 1 ];
        if( j + a <= m )
            for( int i = 1; ( i + b - 1 ) <= n; i++ )
                f[ 1 ][ j ] = max( f[ 1 ][ j ], getsum( i, j + 1, i + b - 1, j + a ) );
        if( j + b <= m )
            for( int i = 1; ( i + a - 1 ) <= n; i++ )
                f[ 1 ][ j ] = max( f[ 1 ][ j ], getsum( i, j + 1, i + a - 1, j + b ) );
    }

    int ans = -INF;
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ ){
            int ff = max( f[ 0 ][ i ] , f[ 1 ][ j ] );
            if( i >= a && j >= b )
                ans = max( ans, getsum( i - a + 1, j - b + 1, i, j ) + ff );
            if( j >= a && i >= b )
                ans = max( ans, getsum( i - b + 1, j - a + 1, i, j ) + ff );
        }
    if( ans == -INF )
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}
