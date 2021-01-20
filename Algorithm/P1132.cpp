#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char ch1[ 10 ], ch2[ 10 ];
int l;

void work( int x1, int y1, int x2, int y2 ){
    cout << ch2[ y2 ];
    if( x1 >= y1 ){
        return;
    }
    for( int i = x1; i <= y1; i++ ){
        if( ch1[ i ] == ch2[ y2 ] ){
            if( x1 <= i - 1 ) work( x1, i - 1, x2, x2 + i - x1 - 1 );
            if( i + 1 <= y1 ) work( i + 1, y1, x2 + i - x1, y2 - 1 );
            return;
        }
    }
}

int main(){
    cin >> ch1 >> ch2;
    l = strlen( ch1 );
    work( 0, l - 1, 0, l - 1 );
    return 0;
}
