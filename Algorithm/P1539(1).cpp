#include <iostream>
#include <cmath>

using namespace std;

int p[6]={1,2,3,5,7,9};
int n;
int num[1000];

bool prime( int x ){
    if( x == 1 ) return false;
    for(int i = 2;i <= sqrt( x ); i++ )
        if(x%i==0) return false;
    return true;
}
int getten( int n0 ){
    int nx = 1;
    while( n0-- > 1) nx *= 10;
    return nx;
}

int main(){
    cin >> n;
    int ansN = 1;
    int gt = getten( n );
    num[ 0 ] = 0;
    for( int i = 0; i < ansN; i++ )
        for( int j = 0; j < 6; j++ ){
            int xx = num[ i ] * 10 + p[ j ];
            if( prime( xx ) ){
                if( xx > gt )
                    cout << xx << endl;
                else
                    num[ ansN++ ] = xx;
            }
        }
    return 0;
}
