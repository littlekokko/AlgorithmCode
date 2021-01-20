#include<iostream>
#include<stdio.h>

using namespace std;

int n,m;
int num[1050][1050];
int ans;
void init(){
    scanf("%d%d", &n, &m );
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            scanf( "%d", &num[ i ][ j ] );
    return;
}

int work1( int x1, int y1, int step1 ){

}

int main(){
    init();
    ans = 0;
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ )
            ans += work1( i , j , 1 ) + work2( i , j , 1 );
    }
    return 0;
}
