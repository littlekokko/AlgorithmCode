#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int n, w;
int num[ 30010 ];
bool cmp( int a, int b ){
    if( a > b )
        return true;
    else
        return false;
}

int main(){
    scanf( "%d", &w );
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ )
        scanf( "%d", &num[ i ] );
    sort( num, num + n, cmp );
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while( l < r ){
        int sum = num[ l ] + num[ r ];
        if( sum <= w ){
            l++;
            r--;
        }
        else{
            l++;
        }
        ans++;
    }
    if( l == r ) ans++;
    printf( "%d\n", ans);
    return 0;
}
