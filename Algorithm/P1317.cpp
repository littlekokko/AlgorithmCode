#include<iostream>
using namespace std;

int main(){
		int N,m;
		int moneys[500];
		int imp[500];
		int dp[30010];
		cin >> N >> m;
		for( int i = 0; i < m; ++i){
            cin >> moneys[ i ] >> imp[ i ];
			imp[ i ] = imp[ i ] * moneys[ i ];
		}

		for( int i = 0; i < m; ++i ){
			for( int j = N; j >= moneys[ i ]; j--){
				if( ( dp[ j - moneys[ i ] ] + imp[ i ] ) > dp[ j ] )
					dp[j] = dp[ j - moneys[ i ] ] + imp[ i ] ;
			}
		}
		cout << dp[ N ] << endl;
		return 0;
}
