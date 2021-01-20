#include<iostream>
using namespace std;
int n,m;
int apple[2020],tall[2020];
bool t[2020];
int main(){
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
        cin >> apple[ i ];
    for( int j = 0; j < m; j++ ){
        cin >> tall[ j ];
        t[ j ] = true;
    }
    for( int i = 0; i < n; i++ ){
        int k = -1;
        int maxt = 0;
        for( int j = 0; j < m; j++ ){
            if( t[ j ] && tall[ j ] < apple[ i ] && maxt < tall[ j ] ) {
                    k = j;
                    maxt = tall[ j ];
            }
        }
        if( k != -1 )
            t[ k ] = false;
    }
    int ans = 0;
    for( int j = 0; j < m; j++ )
        if( t[ j ] ) ans++;
    cout << ans << endl;
    return 0;
}

