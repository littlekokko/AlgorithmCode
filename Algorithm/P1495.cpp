#include<iostream>
#include<string.h>
using namespace std;

int word[30];

bool prime(int x){
    if( x == 1 ) return false;
    if( x == 0 ) return false;
    for( int i = 2; i < x; i++ )
        if( x % i == 0 ) return false;
    return true;
}

int main(){
    string st;
    cin >> st;
    int l = st.length();
    int maxx = 0;
    int minn = 200;
    for( int i = 0; i < 26; i++ )
        word[ i ] = 0;
    for( int i = 0; i < l; i++ )
        word[ st[ i ] - 'a' ]++;
    for( int i = 0; i < 26; i++ ){
        maxx = max( maxx , word[ i ] );
        if( word[ i ] > 0 )
            minn = min( minn , word[ i ] );
    }
    int lw = maxx - minn;
    if( prime( lw ) ){
        cout << "Lucky Word" << endl;
        cout << lw << endl;
    }
    else{
        cout << "No Answer" << endl;
        cout << '0' << endl;
    }
    return 0;
}
