#include<iostream>
#include<algorithm>
using namespace std;

int n, m, x, y, w, ans;
int v[ 10000 ];
int z[ 10000 ];

bool check( int dline, int t ){
    int dl = dline;
    for( int i = t - 1; i >= 0; i-- ){
        if( z[ i ] + y <= dline ) return true;
        if( z[ i ] + x > dl ) return false;
        dl = dl - x;
    }
}

int main(){
    cin >> w;
    while( w-- ){
        cin >> n >> m >> x >> y;
        for( int i = 0; i < m; i++ )
            cin >> v[ i ];
        sort( v , v + m );
        int leftz = 0;
        int rightz = v[ m - 1 ] * n + 1;
        int midz = ( rightz + leftz ) / 2;
        while( rightz > leftz && midz > leftz ){
            int testz = 0;
            for( int i = 0; i < m; i++ )
                testz += midz / v[ i ];
            if( testz >= n ) rightz = midz;
                else leftz = midz;
            midz = ( rightz + leftz ) / 2;
        }
        int timez = rightz;
        int numz = m;
        while( v[ numz - 1 ] > timez ) numz--;
        for( int i = 0; i < numz; i++ )
            z[ i ] = ( timez / v[ i ] ) * v[ i ];
        sort( z , z + numz );

        if( x >= y ){
            ans = z[ numz - 1 ] + y;
        }
        else{
            int lefts = z[ numz - 1 ] + x;
            int rights = z[ numz - 1 ] + y;
            int mids = ( lefts + rights ) / 2;
            while( rights > lefts && mids > lefts ){
                if( check( mids, numz ) ) rights = mids;
                else lefts = mids;
                mids = ( lefts + rights ) / 2;
            }
            ans = rights;
        }
        cout << ans << endl;
    }
    return 0;
}
