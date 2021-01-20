#include<stdio.h>
using namespace std;

int n,x;

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if( x % 2 ) { printf("%d",7); x = x - 3; }
        else {printf("%d",1); x = x - 2; }
        while( x ){
            printf("%d",1);
            x = x - 2;
        }
        printf("\n");
    }
    return 0;
}
