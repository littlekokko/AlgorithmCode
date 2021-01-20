#include<iostream>

using namespace std;

bool num[ 2000 ];
int sum, x, n;
int main(){
    cin >> n;
    sum = 0;
    for( int i = 0; i < 1001; i++ )
        num[ i ] = false;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        if( !num[ x ] ){
            sum++;
            num[ x ] = true;
        }
    }
    cout << sum << endl;
    for( int i = 0; i < 1001; i++ )
        if( num[ i ] )
            cout << i << " ";
    cout << endl;
    return 0;
}
