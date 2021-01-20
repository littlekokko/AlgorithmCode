#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int n, a[ 2000 ], b[ 2000 ];

bool cmd( int x, int y ){
    if( x < y ) return true;
    return false;
}

int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> a[ i ];
    for( int i = 1; i <= n; i++ ) cin >> b[ i ];
    sort( a + 1 , a + n + 1, cmd );
    sort( b + 1 , b + n + 1, cmd );
    int l = 1, r = n;
    int p = 1, q = n;
    int ans = 0;
    int k = 0;
    while( l <= r && p <= q ){
        if( a[ l ] == b[ p ] ){
            k++;
            l++;
            p++;
            continue;
        }
        if( a[ l ] < b[ p ] && k == 0 ){
            ans--;
            q--;
            l++;
            continue;
        }
        if( a[ l ] < b[ p ] && k != 0 ){
            k--;
            l++;
            q--;
            continue;
        }
        if( a[ l ] > b[ p ] ){
            ans++;
            p++;
            l++;
            continue;
        }
    }
    if( k > 1 ) ans = ans + k - 2;
    cout << ans << endl;
    return 0;
}
