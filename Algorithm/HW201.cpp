#include<iostream>
using namespace std;

int n, k;

int main(){
    cin >> n >> k;
    int k1 = k + n - 1;
    int x = 1,y = 1,z = 1;
    for( int i = 1; i <= k1; i++ )
        x *= i;
    for( int i = 1; i <= n; i++ )
        y *= i;
    for( int i = 1; i <= ( k1 - n ); i++ )
        z *= i;
    int ans = x / ( y * z );
    cout << ans << endl;
    return 0;
}
