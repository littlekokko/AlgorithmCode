#include<iostream>

using namespace std;

int n, k, a[ 100 ];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++ )
        cin >> a[ i ];
    int l = 0, r = n - 1, mid;
    while( l <= r ){
        mid = ( l + r ) / 2;
        if( a[ mid ] <= k ) l = mid + 1;
        if( a[ mid ] >= k ) r = mid - 1;
    }
    cout << a[ r ] << " " << a[ l ] << endl;
    return 0;
}
