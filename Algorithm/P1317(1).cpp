#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXV=2005;
int f[MAXV][MAXV];
int h[MAXN];
int sum;
int n;

void init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        sum+=h[i];
    }
}

void DP()
{
    f[0][0]=1;
    for(int k=1;k<=n;k++)
        for(int i=sum;i>=0;i--)
            for(int j=sum;j>=0;j--)
                if(f[i][j])
                {
                    f[i+h[k]][j]=1;
                    f[i][j+h[k]]=1;
                }
    for(int i=sum;i>=1;i--)
        if(f[i][i])
        {
            printf("%d\n",i);
            return;
        }
    printf("Impossible\n");
}

int main()
{
    init();
    DP();
}
