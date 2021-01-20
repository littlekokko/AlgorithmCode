#include<iostream>

using namespace std;

int *foo(){
    int *b = new int [3];
    for(int i = 0; i < 3; i++ )
        b[ i ] = i;
    return b;
}

int main(){
    int *p;
    p = foo();
    for(int i = 0; i < 3; i++ ) cout << p[ i ] << endl;
    delete[] p;
    return 0;
}
