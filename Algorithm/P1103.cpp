#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int L,M;
int road[10050];
int ans;

int main(){
    cin >> L >> M;
    for( int i = 0; i <= L; i++ )
        road[ i ] = 1;
    for( int i = 0; i < M; i++ ){
        int left,right;
        cin >> left >> right;
        if( right < left ){
            left = left ^ right;
            right = left ^ right;
            left = left ^ right;
        }
        for( int j = left; j <= right; j++ )
            road[ j ] = 0;
    }
    for( int i = 0; i <= L; i++ )
        ans += road[ i ];
    cout << ans << endl;
    return 0;
}
