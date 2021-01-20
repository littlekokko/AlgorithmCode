#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char st[ 101 ];
int num[ 101 ], num2[ 400 ], ans[ 400 ];
int stl, ansl, conet;

int main(){
    cin >> st;
    stl = strlen( st );
    conet = 1;
    for( int i = 1; i <= stl; i++ )
        num[ i ] = st[ stl - i ] - '0';
    int tmp, x;
    while( stl ){
        // num % 2
        x = num[ 1 ] & 1;
        num2[ conet++ ] = x;
        num[ 1 ] -= x;
        // num /= 2
        tmp = 0;
        for( int i = stl; i >= 1; i-- ){
            int p = tmp + num[ i ];
            tmp = ( p & 1 ) * 10;
            num[ i ] = p >> 1;
        }
        if( !num[ stl ] ) stl--;
    }
    conet--;
    num2[ 0 ] = 1;
    ansl = 0;
    memset( ans, 0, sizeof( ans ) );
    for( int i = conet - 1; i >= 0; i-- ){
        for( int j = 0; j <= ansl; j++ )
            ans[ j ] *= 2;
        ans[ 0 ] += num2[ i ];
        for( int j = 0; j <= ansl; j++ ){
            tmp = ans[ j ] / 10;
            ans[ j ] %= 10;
            ans[ j + 1 ] += tmp;
        }
        if( ans[ ansl + 1 ] ) ansl++;
    }
    for( int i = ansl; i >= 0; i-- ){
        cout << ans[ i ];
    }
    return 0;
}
