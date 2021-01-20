#include<iostream>
#include<cmath>
using namespace std;

char ch[ 100020 ];

void work( int cap,int type ) {
    int w = 0, l = 0;
    for( int i = 0; i < cap; i++ ) {
        if( ch[ i ] == 'W' )
            w++;
        if( ch[ i ] == 'L')
            l++;
        if( ( ( w == type || l==type ) &&( abs( l - w ) >= 2 ) ) || ( ( w > type || l > type ) &&( abs( l - w ) == 2 ) ) ){
            cout << w << ':' << l;
            w = 0, l = 0;
            cout << endl;
        }
    }
    cout << w << ':' << l;
}
int main() {
    int i = 0;
    while( (ch[ i ] = getchar() ) != EOF ) {
        if( ch[ i ] == 'E' ) break;
        i++;
    }
    work( i, 11 );
    cout << endl << endl;
    work( i, 21 );

    return 0;
}
