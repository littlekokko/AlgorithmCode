#include<iostream>

using namespace std;

const int maxn = 50;

int n, m;
string st[ maxn ];
int road[ maxn ][ maxn ];
int rnum[ maxn ];
bool flag[ maxn ];

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
                    x1 = min( x1, i );
                    x2 = max( x2, i );
                    y1 = min( y1, j );
                    y2 = max( y2, j );
                }
        if( x1 == maxn && y1 == maxn && x2 == -1 && y2 == -1 ) continue;
        flag[ k ] = true;
        for( int i = x1; i <= x2; i++ ){
            for( int j = y1; j <= y2; j++ ){
                if( i == x1 || i == x2 || j == y1 || j == y2 )
                if( st[ i ][ j ] != ck ) {
                    int t = st[ i ][ j ] - 'A';
                    road[ k ][ t ] = 1;
                }
            }
        }
    }
    int sum = 0;
    string ans ="";
    for( int i = 0; i < 26; i++ ){
        if( flag[ i ] ){
            sum++;
            for( int j = 0; j < 26; j++ )
                if( road[ i ][ j ] ) rnum[ i ]++;
        }
    }
    while( sum ){
        for( int i = 25; i >= 0; i-- ){
            if( flag[ i ] && !rnum[ i ] ){
                ans += char(i+'A');
                flag[ i ] = false;
                sum--;
                for( int j = 0; j < 26; j++ )
                    if( road[ j ][ i ] ) rnum[ j ]--;
            }
        }
    }
    for( int i = ans.length() - 1; i >= 0; i-- )
        cout << ans[i];
    cout << endl;
    return 0;
}
