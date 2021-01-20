#include<iostream>
#include<stdio.h>

using namespace std;

int n, x;

int main(){
    cin >> n >> x;
    int ans = 0;
    for( int i = 1; i <= n; i++ ){
        int t = i;
        while( t > 0 ){
            int k = t % 10;
            if( k == x ) ans++;
            t /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}
