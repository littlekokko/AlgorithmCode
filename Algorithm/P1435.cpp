#include<iostream>
#include<stdio.h>
#include<string.h>

int n,f[1100][300]={{0},{1,0},{1,2},{1,4},{1,12}};
void addx(int a[],int b[]){
    int c[300]={0};
    int len=a[0]>b[0]?a[0]:b[0];
    for(int i=1;i<=len;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10000;
        c[i]%=10000;
    }
    len++;
    while(c[len]==0&&len>1)
        len--;
    c[0]=len;
    memcpy(a,c,sizeof(c));
}

void minusx(int a[],int b[]){
    int c[300]={0};
    int len=a[0];
    for(int i=1;i<=len;i++){
        c[i]+=a[i]-b[i];
        if(c[i]<0){
            c[i]+=10000;
            c[i+1]-=1;
        }
    }
    while(c[len]==0&&len>1)
        len--;
    c[0]=len;
    memcpy(a,c,sizeof(c));
}

void Q(int a[]){
    printf("%d",a[a[0]]);
    for(int i=a[0]-1;i>=1;i--)
    printf("%04d",a[i]);
}

int main(){
    scanf("%d",&n);
    if(n<=4){
        printf("%d",f[n][1]);
        return 0;
    }
    int t[300];
    for(int i=5;i<=n;i++){
        memcpy(f[i],f[i-4],sizeof(t));
        addx(f[i],f[i-2]);
        addx(f[i],f[i-2]);
        addx(f[i],f[i-1]);
        addx(f[i],f[i-1]);
        minusx(f[i],f[i-3]);
        minusx(f[i],f[i-3]);
    }
    Q(f[n]);
    return 0;
}
