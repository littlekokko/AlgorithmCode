#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
//ÇÀÒøĞĞO(n*n)
using namespace std;

int n, d;
struct{
    int x;
    int money;
}bank[200001];
int mx[200001];
int ans;

int main(){
    scanf("%d%d",&n,&d);
    for(int i = 0; i < n; i++ ){
        scanf("%d%d",&bank[i].x,&bank[i].money);

    }
    mx[ 0 ] = bank[ 0 ].money;
    for( int i = 1; i < n; i++ ){
        mx[ i ] = max( mx[ i - 1 ], bank[ i ].money );
    }
    ans = 0;
    for( int i = 1; i < n; i++ ){
        int p = i - 1;
        while( ( p >= 0 ) && ( bank[ i ].x - bank[ p ].x < d ) ) p--;
        int k = bank[ i ].money + mx[ p ];
        if( p >= 0 ) ans = max( ans, k );
    }
    cout << ans << endl;
    return 0;
}
