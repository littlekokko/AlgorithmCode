#include<iostream>
#include<string.h>
#include <vector>
using namespace std;

int k,l;
vector<string> c;
string st;
vector<int> cl;
vector<int> ccheck;

bool check(int n){
    for( int i = 0; i < n; i++ )
        if( ccheck[ i ] != cl[ i ] ) return false;
    return true;
}

int main(){

//   ifstream myfile;
//   myfile.open("HW01.txt", ios::in);

    getline(cin,st);
    l = st.length();
    for( int i = 0; i < l; i++ ){
        k *= 10;
        k += st[ i ] - '0';
    }
    int x = 0;
    while( getline(cin,st) ){
        c.push_back(st);
        cl.push_back(st.length());
        ccheck.push_back( 0 );
    }
    while( !check(c.size()) ){
        for( int i = 0; i < c.size(); i++ ){
            if( ccheck[ i ] == cl[ i ] ) continue;
            int t = ccheck[ i ];
            int p = 0;
            while( t < cl[ i ] && p < k ){
                cout << c[ i ][ t ];
                if( c[ i ][ t ] == ',' ) p++;
                t++;
            }
            ccheck[ i ] = t;
            if( !check( c.size() ) && ccheck[ i ] == cl[ i ] ) cout << ',';
        }
    }
    return 0;
}
