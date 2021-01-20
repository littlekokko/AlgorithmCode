#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

string st;
int num[ 11 ];
int conet, sum, mod, l;

int main(){
    cin >> st;
    conet = 1;
    l = st.length();
    for( int i = 0; i < l; i++ ){
        if( st[ i ] != '-' ){
            if( st[ i ] == 'X' )
                num[ conet++ ] = 10;
            else
                num[ conet++ ] = st[ i ] - '0';
        }
    }
    sum = 0;
    for( int i = 1; i < 10; i++ )
        sum += num[ i ] * i;
    mod = sum % 11;
    if( mod == num[ 10 ] ){
        cout << "Right" << endl;
    }
    else{
        for( int i = 0; i < l - 1; i++ )
            cout << st[ i ];
        ( mod == 10 ) ? cout << 'X' << endl : cout << mod <<endl;
    }
    return 0;
}
