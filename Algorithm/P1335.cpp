#include<iostream>
#include<stdio.h>

using namespace std;

int n;
int num[ 10 ][ 10 ];
int smap[ 9 ][ 2 ] = {1,1,1,4,1,7,4,1,4,4,4,7,7,1,7,4,7,7};
int x[ 10 ];
int main(){
    cin >> n;
    while( n-- ){
        for( int i = 1; i <= 9; i++ ){
            for( int j = 1; j <= 9; j++ ){
                cin >> num[ i ][ j ];
            }
        }
        int flag = 0;
        int sum;
        for( int i = 1; i <= 9; i++ ){
            sum = 0;
            for( int j = 1; j <= 9; j++ ) sum += num[ i ][ j ];
            if( sum != 45 ) flag = 1;
        }
        for( int i = 1; i <= 9; i++ ){
            sum = 0;
            for( int j = 1; j <= 9; j++ ) sum += num[ j ][ i ];
            if( sum != 45 ) flag = 1;
        }
        for( int k = 0; k < 9; k++ ){
            sum = 0;
            for( int i = smap[ k ][ 0 ]; i <= smap[ k ][ 0 ] + 2; i++ )
                for( int j = smap[ k ][ 1 ]; j <= smap[ k ][ 1 ] + 2; j++ )
                    sum += num[ i ][ j ];
            if( sum != 45 ) flag = 1;
        }
        for( int i = 1; i <= 9; i++ )
            x[ i ] = 0;
        for( int i = 1; i <= 9; i++ )
            for( int j = 1; j <= 9; j++ )
                x[ num[ i ][ j ] ]++;
        for( int i = 1; i <= 9; i++ )
            if( x[ i ] != 9 ) flag = 1;
        ( flag ) ? cout << "Wrong" << endl : cout << "Right" << endl;
    }
    return 0;
}
