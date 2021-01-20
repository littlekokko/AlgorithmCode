#include<iostream>

using namespace std;

int main(){

    int n = 1;
    for( int i = 0; i < 31; i++ )
        n *= 2;
    cout << n;
 //   2147483647;
    return 0;
}
