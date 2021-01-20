#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a[maxn], len, x, y;
char ch[1000];

void swap(int& a,int& b){
    a=a^b, b=b^a, a=a^b;
}
int getin(){
    len=x=y=0;
    memset(a,0,sizeof(a));
    int lent=strlen(ch);
    if( ch[0]=='[' ){
        for ( int i=0; i<lent; i++ ){
            if( isdigit(ch[i]) ){
                a[len]=a[len]*10+ch[i]-'0';
            }else len++;
        }
        len--;
        return 0;
    } else{
        for ( int i=0; i<lent; i++ ){
            if( isdigit(ch[i]) ){
                x=x*10+ch[i]-'0';
            }else swap(x,y);
        }
        swap(x,y);
        return 1;
    }
}
int gcd(int x, int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    while( scanf("%s", ch)!=EOF ){
        if( getin() ){
            printf("[%d", x/y );
            x=x%y;
            if( x!=0 && y!=0 ) printf(";");
            swap(x,y);
            while( x!=1 && x!=0 && y!=0){
                printf("%d",x/y);
                x=x%y;
                if( x==0 ) break;
                swap(x,y);
                if( x!=1 ) printf(",");
            }
            printf("]\n");
        }else {
            if( len>1 ){
                x=1, y=a[len];
                for ( int i=len-1; i>=1; i-- ){
                    x=y*a[i]+x;
                    if( i!=1 ) swap(x,y);
                }
                int d=gcd(x,y);
                x/=d, y/=d;
                if( y==0 ) printf("%d\n", x);
                else printf("%d/%d\n",x/d,y/d);
            }else printf("%d\n", a[len] );
        }
    }
    return 0;
}
