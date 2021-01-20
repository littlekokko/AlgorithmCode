#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int n,ans;

int main(){
    cin >> n;
    for( int i = 2; i <= sqrt( n ); i++){
        if( n % i == 0 ){
            ans = n / i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
