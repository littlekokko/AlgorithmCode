#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n;
int x, y[ 10010 ];

bool cmp( int a, int b ){
    if( a > b )
        return true;
    else
        return false;
}

int main(){
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ ){
        scanf( "%d %d", &x, &y[ i ] );
    }
    sort( y, y + n, cmp );
    int l = y[ n >> 1 ];
    int sum = 0;
    for( int i = 0; i < n; i++ ){
        sum += abs( y[ i ] - l );
    }
    printf( "%d\n", sum );
    return 0;
}
