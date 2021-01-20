#include<iostream>
#include<stdio.h>

using namespace std;

const int numx = 150001;
int state[ numx ];// x + n = be(x); x + 2n = eat(x);
int n, k, ans;
int getf( int t ){
    if( state[ t ] != t )
        state[ t ] = getf( state[ t ] );
    return state[ t ];
}

int main(){
    scanf( "%d %d", &n, &k );
    for( int i = 1; i <= n*3; i++ ){
        state[ i ] = i;
    }
    ans = 0;
    while( k-- ){
        int a, x, y;
        scanf( "%d %d %d", &a, &x, &y );
        if( x > n || y > n ){
            ans++;
            continue;
        }
        if( a == 1){
            if( getf( x ) == getf( y + n ) || getf( x + n ) == getf( y ) ){
                ans++;
                continue;
            }
            state[ getf( x ) ] = getf( y );
            state[ getf( x + n ) ] = getf( y + n );
            state[ getf( x + 2 * n ) ] = getf( y + 2 * n );
        }
        else{
            if( getf( x ) == getf( y ) || getf( x + n ) == getf( y ) || x == y){
                ans++;
                continue;
            }
            state[ getf( x ) ] = getf( y + n );
            state[ getf( x + n) ] = getf( y + 2 * n );
            state[ getf( x + 2 * n ) ] = getf( y );
        }
    }
    printf( "%d\n", ans );
    return 0;
}
