#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

int T,n,x;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);
        char ch;
        int num[10000];
        int k = 0;
        num[ 0 ] = 0;
        ch = getchar();
        for( int i = 1; i <= n; i++ ){
            cin >> ch;
            num[ i ] =( '0' - ch ) * 2 + 1 + num[ i - 1 ];
        }
        for( int i = 1; i <= n; i++ )
            cout << num[ i ] << " ";
        printf("\n");
    }
    return 0;
}
