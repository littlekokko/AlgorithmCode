#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

int road[ 2 ][ 2 ] = { 0, 1, 0, 2 };
int troad[ 2 ][ 2 ] = { 1, 2, 2, 1 };

int main(){
    srand((int)time(0));
    int testn = 10000;
    int target, k, timez;
    float sum = 0;
    for( int x = 0; x < testn; x++ ){
        target = 0,timez = 0;
        while( target != 2 ){
            k = rand();
            k = k % 2;
            timez = timez + troad[ target ][ k ];
            target = road[ target ][ k ];
        }
        sum += ( timez * 1.0 ) / x;
        cout << sum << endl;
    }
    return 0;
}
