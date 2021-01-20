#include<iostream>
#include<string.h>
using namespace std;

char st[52];
int l,word[52],del[52],w[26]={0};

int main(){//É¾×ÖÄ¸
    cin >> st;
    l = strlen(st);
    for( int i = 0; i < l ; i++ ){
        if( st[ i ] <='Z' ) st[ i ] += 32;
        word[ i ] = st[ i ] - 'a';
    }
    for( int i = l - 1; i >= 0; i-- ){
        if( !w[ word[ i ] ] ) w[ word[ i ] ] = 1;
        else del[ i ] = 1;
    }
    int ans = 26;
    for( int i = 0; del[ i ]; i++) ans = min(ans,word[ i ]);
    cout << char( ans + 'a' ) << endl;
    return 0;
}
