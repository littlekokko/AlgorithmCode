#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

const string block[ 6 ] = {
    { "..+---+" },
    { "./   /|" },
    { "+---+ |" },
    { "|   | +" },
    { "|   |/." },
    { "+---+.." }
};
int num[ 51 ][ 51 ];
int n, m, H, L;
char ans[1001][1001];

void paintblock( int x, int y ){
    for( int i = 0; i <= 5; i++ )
        for( int j = 0; j <= 6; j++ )
            if( block[ i ][ j ] != '.' )
                ans[ x + i ][ y + j ] = block[ i ][ j ];


}

int main(){
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            cin >> num[ i ][ j ];
    int MaxH = 0;
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            MaxH = max( MaxH, 3 * ( num[ i ][ j ] + 1 ) - 2 * i );
    L = 4 * m + 2 * n + 1;
    H = MaxH + 2 * n;
    memset( ans, '.' , sizeof( ans ) );
    for( int i=1; i <= n; i++ )
        for( int j = 1; j <= m; j++ ){
            int sx = MaxH + 2 * ( i - 1 );
            int sy = 2 * ( n - i ) + 4 * j - 3;
            for( int k = 1; k <= num[ i ][ j ]; k++ )
                paintblock( sx - 3 * k, sy );
        }
    for( int i = 1; i <= H; i++ ){
        for( int j = 1; j <= L; j++ )
            cout << ans[ i ][ j ];
        cout << endl;
    }
    return 0;
}
