#include<iostream>
#include<stdio.h>

using namespace std;

int n, k;
int num;
long long sum;
int mod;
int mm[ 100010 ];
int main(){
    scanf( "%d %d", &n, &k );
    sum = 0;
    for( int i = 0; i < k; i++ )
        mm[ i ] = 0;
    for( int i = 1; i <= n; i++ ){
        scanf( "%d", &num );
        sum = sum + num;
        mod = sum % k;
        mm[ mod ]++;
    }
    sum = 0;
    for( int i = 0; i < k; i++ ){
        sum += mm[ i ] * ( mm[ i ] - 1 ) / 2 ;
        sum %= 1234567;
    }
    sum += mm[ 0 ];
    printf( "%d\n", sum );
    return 0;
}
