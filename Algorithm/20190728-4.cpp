#include<iostream>
#include<algorithm>
using namespace std;

int n,ans = 1;
int dp[ 1000 ][ 1000 ];
struct kk{
    int w,l;
}a[1000];

bool cmp(kk x, kk y ){
    if( x.l < y.l )return true;
    if( x.l == y.l && x.w < y.w )return true;
    return false;
}

int main(){
    cin >> n;
    int maxx = 0x7fffffff;
    for( int i = 1; i <= n; i++ ) cin >> a[ i ].l;
    for( int i = 1; i <= n; i++ ) cin >> a[ i ].w;
    sort( a, a + n, cmp );
    for( int i = 0; i <= n; i++ )
        for( int j = 0; j <= n; j++ )
            dp[ i ][ j ] = maxx;
    for( int i = 1; i <= n; i++ ) dp[ i ][ 1 ] = min( dp[ i - 1 ][ 1 ], a[ i ].w );
    for( int i = 2; i <= n ; i++ )
        for( int k = i - 1; k > 0 ; k-- )
            if( ( a[ i ].w * 7 ) >= dp[ i - 1 ][ k ])
                dp[ i ][ k + 1 ] = min( dp[ i ][ k + 1 ] , dp[ i - 1 ][ k ]+ a[ i ].w );
    for( int i = n; i >= 1; i-- )
    for( int j = n; j >= 1; j-- )
        if( dp[ i ][ j ] < maxx ) ans = max( ans, j );
    cout << ans << endl;
    return 0;
}
