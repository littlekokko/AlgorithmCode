#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int n;
int q[ 100000000 ][ 2 ];

int main(){
    cin >> n;
    int s = sqrt( n );
    int ans = n + 1;
    int top = 1;
    memset( q, 0, sizeof(q) );
    q[ 0 ][ 0 ] = 0;
    q[ 0 ][ 1 ] = 0;
    while( top > 0 ){
        int k = top;
        if( q[ k ][ 0 ] == n ) ans = min( ans, q[ k ][ 1 ] );
        else
            if( q[ k ][ 1 ] < 4 ){
                for( int i = s; i > 0; i-- ){
                    int t = i * i;
                    if( q[ k ][ 0 ] + t < n ){
                        top++;
                        q[ top ][ 0 ] = q[ k ][ 0 ] + t;
                        q[ top ][ 1 ] = q[ k ][ 1 ] + 1;
                    }
                }
            }
        top--;
    }
    cout << ans;
    return 0;
}
