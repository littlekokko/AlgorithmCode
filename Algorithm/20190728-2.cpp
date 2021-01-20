#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
string st;
string str[1000];
int main(){
    getline(cin,st);
    int p = 0,n = 0;
    int l = st.length();
    while( p < l ){
        int k = p;
        while( st[ p ] != ' ' && p < l )p++;
        for( int i = k; i < p; i++ )
            str[ n ] += st[ i ];
        p++;
        n++;
    }
    for( int i = 0; i < n; i++ )
        cout << str[ i ] << endl;
    return 0;
}
