#include<iostream>
using namespace std;
int n, k, t = 0;
int main(){
    cin >> n >> k;
    for( ; (t < k) && n != 1; t++ ) n = ( n + 1 ) / 2;
    cout << t + n << endl;
    return 0;
}
