#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

const int maxn = 50;

int n, m;
char st[ maxn ][ maxn ];
string ans;
int road[ maxn ][ maxn ];
int rnum[ maxn ];
bool flag[ maxn ];
int sum = 0;

void dfs( int x ){
    if( x == sum ){
        cout << ans << endl;
        return;
    }
    for( int i = 0; i < 26; i++ ){
        if( flag[ i ] && !rnum[ i ] ){
            ans += char( i + 'A' );
            rnum[ i ] = -1;
            for( int j = 0; j < 26; j++ )
                if( road[ i ][ j ] ) rnum[ j ]--;
            dfs( x + 1 );
            string anss;
            for( int i = 0; i < ans.length() - 1; i++ )
                anss += ans[ i ];
            ans = anss;
            rnum[ i ] = 0;
            for( int j = 0; j < 26; j++ )
                if( road[ i ][ j ] ) rnum[ j ]++;
        }
    }
}

int main(){
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
        cin >> st[ i ];
    for( int i = 0; i < 26; i++ ){
        flag[ i ] = false;
        rnum[ i ] = 0;
    }
    for( int k = 0; k < 26; k++ ){
        char ck = k + 'A';
        int x1 = maxn, y1 = maxn, x2 = -1, y2 = -1;
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                if( st[ i ][ j ] == ck ){
                    x1 = min( x1, i );x2 = max( x2, i );
                    y1 = min( y1, j );y2 = max( y2, j );
                }
        if( x1 == maxn || y1 == maxn || x2 == -1 || y2 == -1 ) continue;
        flag[ k ] = true;
        sum++;
        for( int i = x1; i <= x2; i++ ){
            for( int j = y1; j <= y2; j++ ){
                if( i == x1 || i == x2 || j == y1 || j == y2 )
                if( st[ i ][ j ] != ck && st[ i ][ j ] != '.' ) {
                    int t = st[ i ][ j ] - 'A';
                    if( !road[ k ][ t ] ){
                        road[ k ][ t ] = 1;
                        rnum[ t ]++;
                    }
                }
            }
        }
    }
    dfs( 0 );
    return 0;
}
