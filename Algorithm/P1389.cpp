#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct node{
    int x;
    string st;
}a[ 1010 ];

bool cmp( node p, node q ){
    if( p.x < q.x )
        return true;
    else
        return false;
}

int main(){
    char ch;
    int l = 0;
    do{
        scanf( "%d", &a[ l++ ].x );
        ch = getchar();
    }while( ch != '\n' );
    for( int i = 0; i < l; i++ ){
        cin >> a[ i ].st;
    }
    sort( a, a + l, cmp );
    for( int i = 0; i < l; i++ ){
        cout << a[ i ].st << endl;
    }
    return 0;
}
