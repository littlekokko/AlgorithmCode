#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int H[200];
    int sum[200];
    int dp[200][2020];

    cin >> N;
    sum[ 0 ] = 0;
    for( int i = 1; i <= N; i++ ){
        cin >> H[i];
        sum[ i ] = sum[ i - 1 ] + H[ i ];
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[ 0 ][ 0 ] = 0;
    for( int i = 1; i <= N; i++ ){
        for( int j = 0; j <= sum[ i ]; j++ ){

            dp[ i ][ j ] =dp[ i - 1 ][ j ];

            int h1 = j - H[ i ];
            if( h1 >= 0 )
                dp[ i ][ j ] = max( dp[ i ][ j ] , dp[ i - 1 ][ h1 ] );

            int h2 = H[ i ] + j ;
            if( h2 <= sum[ i - 1 ] )
                dp[ i ][ j ] = max( dp[ i ][ j ] , dp[ i - 1 ][ h2 ] + H[ i ] );

            int h3 = H[ i ] - j;
            if( h3 >= 0 )
                dp[ i ][ j ] = max( dp[ i ][ j ] , dp[ i - 1 ][ h3 ] + h3 );
        }
    }

    if( dp[ N ][ 0 ] > 0 )
        cout << dp[ N ][ 0 ] << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
