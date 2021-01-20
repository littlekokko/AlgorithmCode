#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int ans = 0;
    for( int i = a; i <= b; i++ ){
        int sum1 = 1;
        for(int j= 2; j * j <= i ; j++ )
            if( i % j == 0 )
                sum1 += j + i / j;
        if( sum1 <= i ) continue;
        int sum2 = 1;
        for(int j = 2; j * j <= sum1 ; j++ )
            if( sum1 % j == 0 )
                sum2 += j + sum1 / j;
        if( sum2 == i ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
