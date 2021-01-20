#include<iostream>

using namespace std;

int main(){
    int n;
    int A[50000];
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> A[ i ];
}


int n = A.size();
        int ans = 0;
        int a[50001],b[500001];
        int x, y;
        for( int i = 0; i < n; i++ ){
            a[ i ] = A[ i ] + i;
            b[ i ] = A[ i ] - i;
        }
