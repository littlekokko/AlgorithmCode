#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;

int n, a[ 200 ], s[ 200 ];
int f[ 200 ][ 200 ];
int g[ 200 ][ 200 ];

void init(){
    cin >> n;
    s[ 0 ] = 0;
    for( int i = 1; i <= n; i++ ){
        cin >> a[ i ];
        s[ i ] = s[ i - 1 ] + a[ i ];
    }
}

int getsum( int x, int y ){
    return s[ y ] - s[ x - 1 ];
}

void DP(){
    memset(f,0x3f,sizeof(f));
    for( int i = 1; i <= n; i++ )
        f[ i ][ i ] = 0;
    for( int l = 2; l <= n; l++ )
        for( int i = 1; i <= n - l + 1; i++ ){
            int j = i + l - 1;
            for( int k = i; k < j; k++ )
                if( f[ i ][ k ] + f[ k + 1 ][ j ] + getsum( i , j ) <= f[ i ][ j ] ){
                    f[ i ][ j ] = f[ i ][ k ] + f[ k + 1 ][ j ] + getsum( i , j );
                    g[ i ][ j ] = k;
                }
        }
}

void print( int l, int r ){
    if( l == r ){
        cout << a[ l ];
        return;
    }
    else{
        cout << '(';
        print( l,g[ l ][ r ] );
        cout << '+';
        print( g[ l ][ r ] + 1, r);
        cout << ')';
    }
}

void printsum( int l, int r ){
    if( g[ l ][ r ] == 0 ){
        return;
    }
    else{
        printsum( l , g[ l ][ r ] );
        printsum( g[ l ][ r ] + 1, r );
        cout << getsum( l , r ) << " ";
    }
}

int main(){
    init();
    DP();
    print( 1, n );
    cout << endl;
    cout << f[ 1 ][ n ] << endl;
    printsum( 1, n );
    cout << endl;
    return 0;
}
