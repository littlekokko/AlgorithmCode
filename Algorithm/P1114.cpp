#include<iostream>
#include<stdio.h>

using namespace std;

int n, m;
int num[ 2000 ];
char ch[ 2000 ];

void print( int x){
    if( x == 0 ) printf( "B" );
    if( x == 1 ) printf( "I" );
    if( x == 2 ) printf( "F" );
}

int getf( int a, int b ){
    if( a == 1 && b == 1 ) return 1;
    if( a == 0 && b == 0 ) return 0;
    return 2;
}

int work( int l, int r ){
    if( l == r ){
        num[ l ] = getf( num[ l ], num[ l ] );
        print( num[ l ] );
        return num[ l ];
    }
    else{
        int mid = ( l + r ) / 2;
        int x = work( l, mid );
        int y = work( mid + 1, r );
        int z = getf( x, y );
        print( z );
        return z;
    }
}

int main(){
    scanf( "%d\n", &n );
    cin >> ch;
    m = 1;
    for( int i = 0; i < n; i++ ) m *= 2;
    for( int i = 0; i < m; i++ ){
        num[ i ] = ch[ i ] - '0';
    }
    work( 0, m - 1 );
    return 0;
}
