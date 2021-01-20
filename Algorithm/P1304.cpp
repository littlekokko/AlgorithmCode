#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

string x;
int k , n;
int a[10001];

bool hw( int n ){
    for( int i = 1; i <= n / 2; i++ )
        if( a[ i ] != a[ n - i + 1 ] )
            return false;
    return true;
}

int main(){
    cin >> k >> x;
    n=x.size();
    for(int i = 1; i <= n; i++ ){
        if( x[ i - 1 ] < 65 )
            a[ i ] = x[ i - 1 ] - '0';
        else
            a[ i ] = x[ i - 1 ] - 55;
    }
    int step = 0;
    while( step <= 30 ){
        if( hw( n ) ) {
            cout << "STEP=" << step;
            return 0;
        }

        step++;
        int c[ 10001 ] = { 0 };
        for( int i = 1; i <= n; i++ ){
            c[ i ] = a[ i ] + a[ n - i + 1 ] + c[ i ];
            c[ i + 1 ] += c[ i ] / k;
            c[ i ] %= k;
        }
        if( c[ n + 1 ] != 0 ) n++;
        for( int i = n; i >= 1; i-- )
            a[ i ] = c[ i ];

    }
    cout<<"Impossible!";
    return 0;
}
