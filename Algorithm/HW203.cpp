#include<iostream>

using namespace std;

int n,m;
int num[2][11][11];

int main(){
    cin >> n;
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            cin >> num[ 0 ][ i ][ j ];
    cin >> m;
    m %= 4;
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            num[ 1 ][ j ][ n - i - 1] = num[ 0 ][ i ][ j ];
    if( m / 2 ){
        for( int i = n - 1; i >= 0; i-- ){
            for( int j = n - 1; j >= 0; j-- )
                cout << num[ m%2 ][ i ][ j ] << " ";
            cout << endl;
        }
    }
    else{
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ )
                cout << num[ m%2 ][ i ][ j ] << " ";
            cout << endl;
        }
    }
    return 0;
}
