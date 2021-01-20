#include<iostream>

using namespace std;

int mapp[10000][10000];
int f[10000][10000];
int t[ 4 ][ 2 ] ={1,0,-1,0,0,1,0,-1};
struct{
    int x, y;
}l[100000];

bool judge( int x1, int y1 ){
    if( x1 < 0 || y1 < 0 || x1 >= n || y1 >= m ) return false;
    return true;
}


int main(){
    int n,m;
    cin >> n >> m;
    int p = 0;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            cin >> mapp[ i ][ j ];
            if( mapp[ i ][ j ] ) f[ i ][ j ] = 10001;
            else {
                f[ i ][ j ] = 0;
                l[ p ].x = i;
                l[ p ].y = j;
                p++;
            }
        }
    }
    int q = 0;
    while( q < p ){
        int a = l[ q ].x;
        int b = l[ q ].y;
        int k = f[ a ][ b ];
        for( int i = 0; i < 4; i++ ){
            int c = a + t[ i ][ 0 ];
            int d = b + t[ i ][ 1 ];
            if( judge( c, d ) && ( k + 1 < f[ c ][ d ] ) ){
                f[ c ][ d ] = k + 1;
                l[ p ].x = c;
                l[ p ].y = d;
                p++;
            }
        }
        q++;
    }
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ )
            cout << f[ i ][ j ] << ' ';
        cout << endl;
    }
    return 0;
}
