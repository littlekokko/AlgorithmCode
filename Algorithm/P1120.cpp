#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct node{
    int v;
    int x,y;
}p[ 500 ];

int n, m, k;
int conet;
int sum = 0;

bool cmp( node a, node b ){
    if( a.v > b.v )
        return true;
    else
        return false;
}

int main(){
    scanf( "%d%d%d", &n, &m, &k );
    conet = 0;
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            int l;
            scanf( "%d", &l );
            if( l != 0 ){
                p[ conet ].v = l;
                p[ conet ].x = i;
                p[ conet ].y = j;
                conet++;
            }
        }
    }
    sort( p, p + conet, cmp );
    int tx, ty;
    tx = 0;
    ty = p[ 0 ].y;
    for( int i = 0; i < conet; i++ ){
        k -= abs( p[ i ].y - ty ) + abs( p[ i ].x - tx );
        tx = p[ i ].x;
        ty = p[ i ].y;
        if( k <= tx ) break;
        k--;
        sum += p[ i ].v;
    }
    printf( "%d\n", sum );
    return 0;
}
