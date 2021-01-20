#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s1[110],s2[110];
int num1[210],num2[210],num3[210],num4[210];
int len1,len2,len3,len4;
int ans[210];
int ansmax;
bool cmp(){
    if(len1>len2)return false;
    if(len1<len2)return true;
    for(int i=len1+1;i>=1;i--){
        if(num1[i]<num2[i]) return true;
        if(num1[i]>num2[i]) return false;
    }
    return false;
}
int main(){//高精度除法,高精度乘法,gcd

    //input
    scanf( "%s %s", s1, s2 );
    len1 = strlen( s1 ) - 1;
    len2 = strlen( s2 ) - 1;
    for( int i = len1; i >= 0; i-- )
        num1[ len1 - i + 1 ] = s1[ i ] - '0';
    for( int i = len2; i >= 0; i-- )
        num2[ len2 - i + 1 ] = s2[ i ] - '0';
    len1++;
    len2++;

    // num1 = gcd(a,b);
    while( 1 ){
        if(cmp()){// if (a < b) swap(a,b);
            int temp=len1;
            len1=len2;
            len2=temp;
            memset(num3,0,sizeof(num3));
            memcpy(num3,num2,sizeof(num2));
            memcpy(num2,num1,sizeof(num1));
            memcpy(num1,num3,sizeof(num3));
        }
        if(len2==0&&num2[1]==0)break;
        int own=0;
        int pos=len1-len2;
        for(int i=len1,j=len2;j>0;j--,i--){
            if(num1[i]>num2[j])break;
            if(num1[i]<num2[j]){
                pos--;
                break;
            }
        }
        own=0;
        for(int i=1;i<=len2||own;i++){
            num1[i+pos]-=num2[i]+own;
            own=0;
            if(num1[i+pos]<0){
                num1[i+pos]+=10;
                own=1;
            }
        }
        while( !num1[len1] && len1 ) len1--;
        while( !num2[len2] && len2 ) len2--;
    }

    len3=len1;
    memset(num3,0,sizeof(num3)); // num3 = 0;
    memcpy(num3,num1,sizeof(num1)); // num3 << num1;

    // num4 = a * b;
    len1=strlen(s1)-1;
    len2=strlen(s2)-1;
    for( int i = len1; i >= 0; i-- )
        num1[ len1 - i + 1 ] = s1[ i ] - '0';
    for( int i = len2; i >= 0; i-- )
        num2[ len2 - i + 1 ] = s2[ i ] - '0';
    len1++;
    len2++;
    int in=0;
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2||in;j++){
            num4[i+j-1]+=num1[i]*num2[j]+in;
            in=num4[i+j-1]/10;
            num4[i+j-1]%=10;
            len4=max(len4,i+j-1);
        }

    // ans = num4 / num3;
    while( 1 ){
        if( len4 == 0 && num4[ 1 ] == 0 ) break;
        int own=0;
        int pos=len4-len3;
        for(int i=len4,j=len3;i>0;j--,i--){
            if(num4[i]>num3[j])break;
            if(num4[i]<num3[j]){
                pos--;
                break;
            }
        }
        own=0;
        for(int i=1;i<=len3||own;i++){
            num4[i+pos]-=num3[i]+own;
            own=0;
            if(num4[i+pos]<0){
                num4[i+pos]+=10;
                own=1;
            }
        }
        ans[pos+1]++;
        ansmax=max(pos+1,ansmax);
        while( !num4[ len4 ] && len4 ) len4--;
        while( !num3[ len3 ] && len3 ) len3--;
    }

    //output
    for(int i=ansmax;i>=1;i--)
        printf("%d",ans[i]);
    return 0;
}
