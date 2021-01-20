#include<iostream>
#include<stdio.h>

using namespace std;

int top, ans, f[100000];
int n, l, x;

int main(){//用数组模拟栈操作 85ms 456.0 KiB
    scanf( "%d", &n );
    top = 0;
    ans = 0;
    for( int i = 0; i < n; i++ ){
        scanf( "%d", &x );
        while( top ){
            ans = max( ans, f[ top ] ^ x );
            if( f[ top ] >= x ) break;
            top--;
        }
        f[ ++top ] = x;
    }
    printf( "%d\n", ans );
    return 0;
}
