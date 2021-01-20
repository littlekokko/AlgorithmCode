#include<iostream>

using namespace std;

int main(){
    int S,M,T;
    int dp[300050];
    int ansTime = 0;
    cin >> M >> S >> T;
    dp[ 0 ] = 0;
    for( int i = 1; i <= T; ++i ){
        if( M >= 10 ){
            dp[ i ] = dp[ i - 1 ] + 60;
            M = M - 10;
        }
        else{
            dp[ i ] = dp[ i - 1 ];
            M = M + 4;
        }
    }
    for( int i = 1; i <= T; ++i ){
        if( dp[ i ] < dp[ i - 1 ] + 17 ){
            dp[ i ] = dp[ i - 1 ] + 17;
        }
        if( dp[ i ] >= S ){
            ansTime = i;
            break;
        }
    }
    if( dp[ T ] < S ){
        cout << "No" << endl;
        cout << dp[ T ] << endl;
    }
    else{
        cout << "Yes" << endl;
        cout << ansTime << endl;
    }

    return 0;
}
