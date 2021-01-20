#include<iostream>

using namespace std;

int main(){
    int f[50001];
    int n, x, y, ans, sum = 0;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        sum = sum + x;
        f[ i ] = sum;
    }
    x = -1; y = -2;
    for( int i = 0; i < n; i++ ){
        if( sum == f[ i ] * 3 ){
            x = i;
            ans = f[ i ];
            break;
        }
    }
    if( x != -1 ){
        for( int i = x + 1; i < n ; i++ ){
            if( f[ i ] == ans * 2 ){
                y = i;
                break;
            }
        }
    }
    if( y > x ) cout << "true" << endl;
        else cout << "false" << endl;
    return 0;
}
