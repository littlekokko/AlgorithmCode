#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;

int f[100];
int k, n = 0;
int ans[ 1001 ];

int main(){
    ifstream fin;
    freopen("vivo001.in","r",stdin);
    cin >> k;
    memset(ans,0,sizeof(ans));
    while(cin >> f[ n ]) n++;
    n /= 2;
    for( int i = 0; i < n; i++ )
        for( int j = k; j >= f[ i ]; j-- )
            ans[ j ] = max( ans[ j ], ans[ j - f[ i ] ] + f[ i + n ] );
    cout << ans[ k ] << endl;
    fclose(stdin);
    return 0;
}
