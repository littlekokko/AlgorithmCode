#include<iostream>

using namespace std;

int main(){

    int n,t;
    int tm[200],lk[200];
    int dp[2000];
    cin >> n >> t;
    for( int i = 0; i <= t; ++i ) dp[ i ] = 0;
    for( int i = 0; i < n; ++i)
        cin >> lk[ i ] >> tm[ i ];
    for( int j = 0; j < n; ++j)
        for( int i = t; i >= tm[ j ]; --i ){
            dp[ i ] = max( dp[ i ] , dp[ i - tm[ j ] ] + lk[ j ] );
        }
    cout << dp[ t ];
    return 0;
}
