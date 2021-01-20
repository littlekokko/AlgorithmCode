#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

const double g = 0.6180339887498949;
int n;
double a[ 30001 ];
double ans = 100000.0;
int ansx, ansy;

int work( double e, int p ){
    int l = 1;
    int r = p;
    while( l <= r ){
        int mid = ( l + r ) / 2;
        if( a[ mid ] <= e )
            l = mid + 1;
        else
            r = mid - 1;
    }
    double x = fabs( a[ l - 1 ] - e );
    double y = fabs( a[ l ] - e );
    double z = fabs( a[ l + 1 ] - e );
    if( x < y && x < z )
        return l - 1;
    if( y < x && y < z )
        return l;
    return l + 1;
}

int main(){//二分 195ms
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> a[ i ];
    sort( a + 1, a + n + 1 );
    for( int i = 1; i <= n; i++ ){
        double t = double( a[ i ] ) * g ;
        int k = work( t, i );
        double temp = fabs( a[ k ] / a[ i ] - g ); // t - a[ k ] 精度不够
        if( temp < ans ){
            ans = temp;
            ansx = a[ k ];
            ansy = a[ i ];
        }
    }
    cout << ansx << endl << ansy << endl;
    return 0;
}
