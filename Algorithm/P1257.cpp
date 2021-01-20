#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n;
struct node{
    char name[10010],num[10010];
    int len;
}p[2000];

int worknum( char *x, char *y, int l ){
    for( int i = 0; i < l; i++ ){
        if( x[ i ] < y[ i ] ) return 2;
        if( x[ i ] > y[ i ] ) return 1;
    }
    return 0;
}

bool workname( char *x, char*y ){
    int lenx = strlen( x );
    int leny = strlen( y );
    for(int i=0; i < min( lenx, leny ); i++ ){
        if( x[ i ] < y[ i ] ) return true;
        if( x[ i ] > y[ i ] ) return false;
    }
    if( lenx < leny ) return true;
    return false;
}

bool cmp( node x, node y ){
    if( x.len > y.len ) return true;
    else if( x.len < y.len ) return false;
    else{
        int k = worknum( x.num, y.num, x.len );
        if( k == 1 )
            return true;
        if( k == 2 )
            return false;
        if( k == 0 )
            return workname( x.name, y.name );
    }
}

int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> p[ i ].name;
        cin >> p[ i ].num;
        p[ i ].len = strlen( p[ i ].num );
    }
    sort( p + 1, p + n + 1, cmp );
    for( int i = 1; i <= n; i++ ){
        int k = strlen( p[ i ].name );
        for( int j = 0; j < k; j++ )
            cout << p[ i ].name[ j ];
        cout << endl;
    }
    return 0;
}
