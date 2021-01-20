#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,p;
int father[5050];
int x0,y0;

int findfather(int x){
    if( father[ x ] == x )
        return x;
    else
        return father[ x ] = findfather( father[ x ] );
}

int main(){//²¢²é¼¯
    cin >> n >> m >> p;
    for( int i = 1; i <= n; i++ )
        father[ i ] = i;
    for( int i = 0; i < m; i++ ){
        cin >> x0 >> y0;
        if( findfather( x0 ) != findfather( y0 ) )
            father[ findfather( y0 ) ] = findfather( x0 );
    }
    for( int i = 0; i < p; i++ ){
        cin >> x0 >> y0;
        if( findfather( x0 ) != findfather( y0 ) )
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
