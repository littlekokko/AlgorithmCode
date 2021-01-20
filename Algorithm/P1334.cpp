#include<iostream>
using namespace std;

int main(){
    int Weight,Volume;
    int W[10009],V[10009],K[10009];
    int n;
    long long f[1000][1000];
    cin >> Weight >> Volume >> n;
    for( int i = 0; i <= Weight; i++ )
        for( int j = 0; j <= Volume; j++ )
            f[ i ][ j ] = 0;
    for( int i = 0; i < n; ++i )
        cin >> W[i] >> V[i] >> K[i];
    for( int k = 0; k < n; k++ )
        for( int i = Weight; i >= W[ k ]; i-- )
            for( int j = Volume; j >= V[ k ]; j-- )
                f[ i ][ j ] = max( f[ i ][ j ], f[ i - W[ k ] ][ j - V[ k ] ] + K[ k ] );
    cout << f[ Weight ][ Volume ];
    return 0;
}
