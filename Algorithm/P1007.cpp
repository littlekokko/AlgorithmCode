#include<iostream>
#include<math.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

int n;
double r;
double sum;
double x[200],y[200];

double sqr(double k){
    return k*k;
}

int main(){
    cin >> n >> r;
    for( int i = 0; i < n; i++ ){
        cin >> x[ i ] >> y[ i ];
        if( i > 0 ) sum += sqrt( sqr( x[ i ] - x[ i - 1 ] ) + sqr( y[ i ] - y[ i - 1] ) );
    }
    sum += sqrt( sqr( x[ 0 ] - x[ n - 1 ] ) + sqr( y[ 0 ] - y [ n - 1 ])  );
    sum += ( 2 * 3.1415 ) * r;
    cout << setprecision(2) << fixed << sum << endl;
    return 0;
}
