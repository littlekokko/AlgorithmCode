#include<iostream>

using namespace std;

int n, d;
struct{
    int x;
    int money;
}bank[200001];
int mx[200001],my[200001];

int main(){
    cin >> n >> d;
    for(int i = 0; i < n; i++ ){
        cin >> bank[i].x >> bank[i].money;

    }
    mx[ 0 ] = bank[ 0 ].money;
    for( int i = 1; i < n; i++ ){
        mx[ i ] = max( mx[ i - 1 ], bank[ i ].money );
    }
    my[ n - 1 ] = bank[ n - 1 ].money;
    for( int i = n - 2; i >= 0 ; i-- ){
        my[ i ] = max( my[ i + 1 ], bank[ i ].money );
    }
    int ans = 0;
    int p = 0, q = 1;
    while( p < n - 1 && q < n){
        if( bank[ q ]. x - bank[ p ].x >= d ) ans = max( ans, mx[ p ] + my[ q ] );
        if( ( q - p > 1 ) && bank[ q ]. x - bank[ p ].x >= d )
            p++;
        else
            q++;
    }
    cout << ans << endl;
    return 0;
}
