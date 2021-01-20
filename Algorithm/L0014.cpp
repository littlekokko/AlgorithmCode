#include<iostream>

using namespace std;

int main(){
        string strs[20];
        for( int i = 0; i < 3; i++ )
            cin >> strs[ i ];
        int j = 0;
        int m = strs[0].length();
        int n = 3;
        int t;
        string ans="";
        while( j < m){
            t = 1;
            for( int i = 1; i < n; i++ ){
                if( strs[ i ].length() < j ) break;
                if( strs[ i ][ j ] == strs[ 0 ][ j ] ) t++;
            }
            if( t == n ){
               cout << j << "      " << strs[ 0 ][ j ] << endl;
               ans[ j ] = strs[ 0 ][ j ];
            }
            else break;
            j++;
        }
        for( int i = 0; i < j; i++ )
            cout << ans[ i ];
        return 0;
}

