#include<iostream>

using namespace std;

int n[10];
int x;
int ans = 0;
int main(){
    for( int i = 0; i < 10; i++ ){
        cin >> n[ i ];
        n[ i ] -= 30;
    }
    cin >> x;
    for( int i = 0; i < 10; i++ )
        if( n[ i ] <= x ) ans++;
    cout << ans << endl;
    return 0;
}
