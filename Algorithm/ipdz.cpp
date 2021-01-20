#include<iostream>
#include<string.h>

using namespace std;

char st[15];
int l,ans;
int f[5];
int ansf[1000][5];

void judge(int x){
    if( x != l ) return;
    for( int i = 1; i <= 4; i++ )
        if( f[ i ] > 255 || f[ i ] < 0 ) return;
    for( int i = 1; i <= 4; i++ )
        ansf[ ans ][ i ]=f[ i ];
    ans++;
}

void work(int n,int t,int k){
    if( t >= l ) return;
    if( k > 1 && st[ t ] == '0' ) return;
    int p = 0;
    for( int i = 0; i < k; i++ ){
        p *= 10;
        p += int( st[ t + i ] - '0' );
    }
    f[ n ] = p;
    if( n == 4 ){
        judge( t + k );
        return;
    }
    for( int i = 1; i <= 3; i++ )
        work( n + 1, t + k  , i );
}

void output(){
    cout <<'[' << '"' << ansf[ 0 ][ 1 ] ;
    for( int i = 2; i <= 4; i++ )
        cout << '.' << ansf[ 0 ][ i ];
    cout << '"';
    for( int j = 1; j < ans ; j++ ){
        cout << ',' << '"' << ansf[ j ][ 1 ] ;
        for( int i = 2; i <= 4; i++ )
            cout << '.' << ansf[ j ][ i ];
        cout << '"';
    }
    cout << ']' << endl;
}

int main(){
    cin >> st;
    l = strlen(st);
    ans = 0;
    for( int i = 1 ; i <= 3; i++ )
        work( 1, 0, i );
    output();
    return 0;
}
