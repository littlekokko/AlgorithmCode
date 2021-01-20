#include<iostream>

using namespace std;

int n;
int num[ 10000 ],f[ 10000 ];
int l, r, mid, target;
int main(){
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> num[ i ];
    f[ 0 ] = num[ 0 ];
    int p = 1;
    for( int i = 1; i < n; i++ ){
        if( num[ i ] > f[ p - 1] ){ f[ p++ ] = num[ i ]; continue; }
        target = num[ i ], l = 0, r = p;
        while( l < r ){
            mid = ( l + r ) / 2;
            if( f[ mid ] >= target ) r = mid;
            else l = mid + 1;
        }
        f[ l ] = target;
    }
    cout << p << endl;
    return 0;
}
