#include<iostream>

using namespace std;

const int f[ 4 ][ 2 ] = { 0,1,1,0,0,-1,-1,0};
int n, m;
int mp[1000][1000];
int main(){
    cin >> n >> m;
    for( int i = 0; i <= n + 1; i++ )
        for( int j = 0; j <= m + 1; j++ )
            mp [ i ][ j ] = -1;
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            cin >> mp[ i ][ j ];
    int num = n * m;
    int x = 1, y = 1;
    int p = 0;
    while( num-- ){
        cout << mp[ x ][ y ] << " ";
        mp[ x ][ y ] = -1;
        if( mp[ x + f[ p ][ 0 ] ][ y + f[ p ][ 1 ] ] == -1 ) p = ( p + 1 ) % 4;
        x += f[ p ][ 0 ];
        y += f[ p ][ 1 ];
    }
    return 0;
}
