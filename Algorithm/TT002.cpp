#include<iostream>
using namespace std;
int n;
int sum[3000];
int a[3000];
int f[3000][3000];

int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> a[ i ];
    sum[ n + 1 ] = 0;
    for( int i = n; i >= 1; i-- )
        sum[ i ] = sum[ i + 1 ] + a[ i ];
  //  for( int i = 1; i <= n; i++ )
  //      f[ n - i ][ i ] = sum[ i ];
    for( int i = 1; i <= 2 * n; i++ )
        f[ n ][ i ] = a[ n ];
    for( int i = n; i >= 1; i-- ){
        for( int k = 1; k <= n; k++ ){
            int maxk = 0;
            for( int j = 1; j <= 2 * k; j++ )
                maxk = max( maxk, f[ i + k ][ j ] );
            f[ i ][ k ] = sum[ i ] - maxk;
        }
    }
  /*  for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= 2 * n; j++ )
            cout << f[ i ][ j ] << " ";
        cout << endl;
    }*/
    cout << max( f[ 1 ][ 1 ], f[ 1 ][ 2 ] )  << endl;
    return 0;
}
