#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

const double g = 0.6180339887498949;
int n, a[ 30001 ];
double b[ 30001 ];
double k, ans;
int ansi, ansj;
bool cmp( int x, int y ){
    if( x < y )
        return true;
    else
        return false;
}

int main(){//Ã¶¾Ù 4816ms
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> a[ i ];
    sort( a, a + n, cmp );
    ans = 100000.000000000000000;
    ansi = 0;
    ansj = 0;
    for( int i = 0; i < n; i++ )
        b[ i ] = double( a[ i ] ) * g;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < i; j++ ){
            k = fabs( b[ i ] - double( a[ j ] ) );
            if( k < ans ){
                ansi = a[ i ];
                ansj = a[ j ];
                ans = k;
            }
        }
    }
    cout << ansj << endl << ansi;
    return 0;
}
