#include<iostream>

using namespace std;

int flag[ 10 ];
int ans[ 10 ];

void dfs( int step ){
    if( step == 9 ){
        for( int i = 0; i <= 8; i++ )
            cout << ans[ i ];
        cout << endl;
        return;
    }
    else{
        for( int i = 0; i <= 8; i++ ){
            if( flag[ i ] ){
                flag[ i ] = 0;
                ans[ step ] = i;
                dfs( step + 1 );
                flag[ i ] = 1;
            }
        }
        return;
    }
}

int main(){
    int l = 1;
    int k = 9;
    for( int i = 0; i <= 8; i++ )
        flag[ i ] = 1;
    //dfs( 0 );
    for( int i = 1; i <= 9; i++ ){
        l *= i;
    }
    cout << l;
    return 0;
}
