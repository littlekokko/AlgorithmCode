#include<iostream>
#include<math.h>

using namespace std;

long long ans[10000];

int main(){
    long long n = 1;
    long long t = 1;
    while( n < 19){
        cout << endl;
        cout << endl;
        n++;
        t = t * 10 + 1;
        long long q = t;
        long long x = 0;
        cout << t << endl;
        while( q > 1 ){
            for( long long i = 2; i <= t ; i++ ){
                if( q % i == 0 ){
                    ans[ x ] = i;
                    q = q / i;
                    x++;
                    break;
                }
            }
        }
        for( long long i = 0; i < x; i++ )
            cout << ans[ i ] << ' ';
    }

    return 0;
}
