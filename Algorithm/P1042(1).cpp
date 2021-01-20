#include<iostream>
#include<algorithm>
using namespace std;

int m,n,num;
int a[100020];

bool cmp(int a, int b){
    if( a < b ) return true;
    else return false;
}

bool prime( int x ){
    if( x == 1 ) return false;
    for( int i = 2; i * i <= x; i++ )
        if( x % i == 0 ) return false;
    return true;
}

int hw(int t){
    int l = t;
    int q = 0;
    int p[ 20 ];
    while( l > 0 ){
        p[ q++ ] = l % 10;
        l /= 10;
    }
    l = t;
    for( int i = 1; i < q; i++ ){
        l *= 10;
        l += p[ i ];
    }
    return l;
}

int main(){
    cin >> m >> n;
    a[ 0 ] = 11;
    num = 1;
    for( int i = 1; i <= 9999; i++ ){
        int k = hw( i );
        if( prime( k ) ) a[ num++ ] = k;
    }
    sort( a, a + num, cmp );
    for( int i = 0; i < num; i++ )
        if( a[ i ] >= m && a[ i ] <= n )
            cout << a[i] << endl;
    return 0;
}
