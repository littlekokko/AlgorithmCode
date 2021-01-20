#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int n, k;
int E[ 11 ];
struct node{
    int x;
    int w;
}a[ 50010 ];

bool cmp( node a, node b ){
    if( a.w > b.w ) return true;
    if( ( a.w == b.w ) && ( a.x < b.x ) ) return true;
    return false;
}

int main(){
    scanf( "%d %d", &n, &k );
    for( int i = 1; i <= 10; i++ )
        scanf( "%d", &E[ i ] );
    for( int i = 1; i <= n; i++ ){
        scanf( "%d", &a[ i ].w );
        a[ i ].x = i;
    }
    sort( a + 1, a + n + 1, cmp );
    int j = 1;
    for( int i = 1; i <= n; i++ ){
        a[ i ].w += E[ j ];
        ( j == 10 ) ? j = 1 : j++;
    }
    sort( a + 1, a + n + 1, cmp );
    for( int i = 1; i <= k; i++ )
        cout << a[ i ].x << " ";
    return 0;
}
