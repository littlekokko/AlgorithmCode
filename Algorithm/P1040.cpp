#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<iostream>
using namespace std;

char st1[10002],st2[10002];
int a[10002],b[10002],c[20010];
int l1,l2;

void init(){
    for( int i = 0; i < l1; i++ )
        a[ l1 - i - 1 ] = st1[ i ] - '0' ;
    for( int i = 0; i < l2; i++ )
        b[ l2 - i - 1 ] = st2[ i ] - '0' ;
}

int main(){//高精度乘法
    scanf( "%s %s", st1, st2 );
    l1 = strlen( st1 );
    l2 = strlen( st2 );
    init();
    for( int i = 0; i < l1; i++ )
        for( int j = 0; j < l2; j++ ){
            c[ i + j ] += a[ i ] * b[ j ];
            if( c[ i + j ] >= 10 ){
                c[ i + j + 1] += c[ i + j ] / 10;
                c[ i + j ] %= 10;
            }
        }
    int k = l1 + l2;
    while( !c[ k ] ) k--;
    while( k >= 0 ) cout << c[ k-- ];
    return 0;
}
