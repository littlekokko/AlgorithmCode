#include<iostream>
#include<string.h>

using namespace std;

string ans;
string s1,s2;

void finds(string pre,string mid){
    int keyx,l = pre.size();
    char key = pre[ 0 ];
    string prex = "", midx = "", prey = "", midy = "";
    for( int i = 0; i < l; i++ )
        if( mid[ i ] == key )
            keyx = i;
    for( int i = 0; i < keyx; i++ )
        prex += pre[ i + 1 ],midx += mid[ i ];
    for( int i = keyx + 1; i < l; i++ )
        prey += pre[ i ],midy += mid[ i ];
    if( keyx > 0 ) finds(prex, midx );
    if( keyx < l - 1 ) finds(prey, midy );
    ans += key;
    return;
}

int main(){
    cin >> s1 >> s2;
    finds( s1, s2 );
    cout << ans << endl;
    return 0;
}
