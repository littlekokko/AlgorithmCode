#include<iostream>

using namespace std;

int n;
int edges[200000][2];
char labels[100000];
int ans[100000][26];

int main(){
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> edges[ i ][ 0 ] >> edges[ i ][ 1 ];
    for( int i = 0; i < n; i++ )
        cin >> labels[ i ];
    for( int i = 0; i < n; i++ ){
        edges[ i + n ][ 0 ] = edges[ i ][ 1 ];
        edges[ i + n ][ 1 ] = edges[ i ][ 0 ];
    }
    sort(edges, 2 * n, cmp );
    return 0;
}
