#include<iostream>
using namespace std;

int pre[100001];
int ans[100001];
int n, x, y, sum = 0;
int find(int x){
    if(x != pre[ x ] ) pre[ x ] = find( pre[ x ] );
    return pre[ x ];
}
void merge(int x, int y){
    int fx = find( x );
    int fy = find( y );
    if( fx != fy )
        pre[ fx ] = fy;
}

int main(){
    cin >> n;
    for( int i = 0; i <= n; i++ ) pre[ i ] = i,ans[ i ] = 0;
    for( int i = 0; i < n - 1; i++ ){
        cin >> x >> y;
        if( y != 1 ) merge( x, y );
    }
    for( int i = 2; i < n; i++ ){
        ans[ pre[ i ] ]++;
        sum = max( ans[ pre[ i ] ], sum );
    }
    cout << sum << endl;
    return 0;
}
