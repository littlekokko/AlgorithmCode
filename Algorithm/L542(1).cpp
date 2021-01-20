#include<iostream>

using namespace std;

int mapp[ 10000 ][ 10000 ];
int ans[ 10000 ][ 10000 ];
int n,m;
int t[ 4 ][ 2 ] ={1,0,-1,0,0,1,0,-1};
bool judge( int x1, int y1 ){
    if( x1 < 0 || y1 < 0 || x1 >= n || y1 >= m ) return false;
    return true;
}
void work( int x, int y){
    for( int i = 0; i < 4; i++ ){
        int a = x + t[ i ][ 0 ];
        int b = y + t[ i ][ 1 ];
        if( judge( a, b ) ) continue;
        int k = ans[ x ][ y ];
        if( k + 1 < ans[ a ][ b ] ){
            ans[ a ][ b ] = k + 1;
            work( a, b );
        }
    }
}

int main(){
    cin >> n >> m;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            cin >> mapp[ i ][ j ];
            if( mapp[ i ][ j ] ) ans[ i ][ j ] = 10001;
            else {
                ans[ i ][ j ] = 0;
            }
        }
    }
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ )
            if( !ans[ i ][ j ] ) work( i , j );
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ )
            cout << ans[ i ][ j ] << ' ';
        cout << endl;
    }
    return 0;
}
