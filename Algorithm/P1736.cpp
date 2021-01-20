#include<iostream>

using namespace std;

int n,x,y,ans;
int a[10001];
int b[10001];
int c[10001];
int d[10001];

int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        int dx,dy;
        cin >> a[ i ] >> b[ i ] >> dx >> dy;
        c[ i ] = a[ i ] + dx;
        d[ i ] = b[ i ] + dy;
    }
    ans=-1;
    cin >> x >> y;
    for( int i = 1; i <= n; i++ )
        if( a[ i ] <= x && x <= c[ i ] && b[ i ] <= y && y <= d[ i ] )
            ans = i;
    cout << ans << endl;
    return 0;
}
