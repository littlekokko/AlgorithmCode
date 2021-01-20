#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int P,Q;
int product,ans;

int gcd(int a, int b) {
    if (a < b){
        a=a^b;
        b=a^b;
        a=a^b;
    }
    int r = a % b;
    while( r ){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main(){

    cin >> P >> Q;
    product = P * Q;

    for( int i = 2; i <= sqrt(product); i++ ){
        if( product % i == 0 ){
            int j = product / i;
            if( gcd( i , j ) == P) ans++;
        }
    }
    cout << ans*2 << endl;

    return 0;
}
