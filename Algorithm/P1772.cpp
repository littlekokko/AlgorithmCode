#include<iostream>
#include<stdio.h>

using namespace std;

bool check( int p, int s, int q ){
    int num[ 10 ];
    int t;
    for( int i = 1; i <= 9; i++ )
        num[ i ] = 0;
    while( p > 0 ){
        t = p % 10;
        if( num[ t ] ) return false;
        num[ t ] = 1;
        p /= 10;
    }
    while( s > 0 ){
        t = s % 10;
        if( num[ t ] ) return false;
        num[ t ] = 1;
        s /= 10;
    }
    while( q > 0 ){
        t = q % 10;
        if( num[ t ] ) return false;
        num[ t ] = 1;
        q /= 10;
    }
    return true;
}

int main(){
    for( int i = 100; i <= 333; i++ ){
        int a, b, c;
        a = i;
        b = i * 2;
        c = i * 3;
        if( check( a, b, c ) )
            printf( "%d %d %d\n", a, b, c );
    }
    return 0;
}
