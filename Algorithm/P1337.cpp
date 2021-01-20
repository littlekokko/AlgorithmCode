#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int n, mark, ans[ 10 ],ansmap[ 16 ];
int jig[ 10 ][ 16 ];

void judgemap(){
    for( int i = 0; i < 16; i++ ) ansmap[ i ] = 0;
    for( int i = 1; i <= n; i++ )
        for( int k = 0; k < 16 - ans[ i ]; k++ )
            if( jig[ i ][ k ] ){
                if( ansmap[ ans[ i ] + k ] ) return;
                ansmap[ ans[ i ] + k ] = i;
            }
    int x = 1;
    for( int i = 0; i < 16; i++ )
        if( !ansmap[ i ] ) x = 0;
    if( x ) mark = 1;
    return;
}

void dfs( int x ){
    if( x <= n )
        for( int i = 0; i < 16; i++ ){
                ans[ x ] = i;
                dfs( x + 1 );
                if( mark ) return;
        }
    else judgemap();
}

int main(){
    cin >> n;
    int l, w;
    char ch;
    memset( jig, sizeof( jig ), 0 );
    for( int i = 1; i <= n; i++ ){
        cin >> l >> w;
        for( int p = 0; p < l; p++ )
            for( int q = 0; q < w; q++ ){
                cin >> ch;
                if( ch == '1' ) jig[ i ][ p * 4 + q ] = 1;
            }
    }
    mark = 0;
    dfs( 1 );
    if( mark )
        for( int i = 0; i < 16; i++ ){
            cout << ansmap[ i ];
            if( ( i + 1 ) % 4 == 0 ) cout << endl;
        }
    else cout << "No solution possible" << endl;
    return 0;
}
