#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

int n, x, ans;
stack <int> f;

int main(){//Õ»²Ù×÷ 142ms 480.0 KiB
    scanf( "%d", &n );
    ans = 0;
    for( int i = 0; i < n; i++ ){
        scanf( "%d", &x );
        while( !f.empty() ){
            ans = max( ans, ( f.top() ^ x ) );
            if( f.top() >= x ) break;
            f.pop();
        }
        f.push( x );
    }
    printf( "%d\n", ans );
    return 0;
}

