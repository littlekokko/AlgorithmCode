#include<iostream>

using namespace std;

int n;
int num[120];
int ans = 0;
int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> num[ i ];
    for( int i = 1; i <= n - 1; i++ ){
        for( int j = i + 1; j <= n; j++ ){
            if( num[ i ] > num[ j ] ){
                int t = num[ i ];
                num[ i ] = num[ j ];
                num[ j ] = t;
            }
        }
    }
    for( int k = 3; k <=n; k++ ){
        int x = 0;
        for( int i = 0; i <= k - 2; i++ ){
            for( int j = i + 1; j <= k - 1; j++ ){
                if( (num[ i ] + num[ j ]) == num[ k ] ){
                    x = 1;
                }
            }
        }
        if( x ) ans++;
    }
    cout << ans << endl;
    return 0;
}
