#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct{
    char s1[1000],s2[1000];
}ss[10000];
int min(int a,int b,int c) {
    int t = a < b ? a : b;
    return t < c ? t : c;
}
int editDistance(int len1,int len2,int t)
{
    int** d=new int*[len1+1];
    for(int k=0;k<=len1;k++)
        d[k]=new int[len2+1];
    int i,j;
    for(i = 0;i <= len1;i++)
        d[i][0] = i;
    for(j = 0;j <= len2;j++)
        d[0][j] = j;
    for(i = 1;i <= len1;i++)
        for(j = 1;j <= len2;j++)
        {
            int cost = ss[t].s1[i] == ss[t].s2[j] ? 0 : 1;
            int deletion = d[i-1][j] + 1;
            int insertion = d[i][j-1] + 1;
            int substitution = d[i-1][j-1] + cost;
            d[i][j] = min(deletion,insertion,substitution);
        }
     int a = d[len1][len2];
        for(int k=0;i<=len1;k++)
            delete[] d[k];
        delete[] d;
    return a;
}
int main(){
    int kkk;
    int ans = 0;
    cin >> kkk;
    for( int i = 0; i < kkk; i++ )
        scanf("%s",ss[i].s1);
    for( int i = 0; i < kkk; i++ )
        scanf("%s",ss[i].s2);
    for( int i = 0; i < kkk; i++ )
        ans += editDistance(strlen(ss[i].s1),strlen(ss[i].s2),i);
    cout << ans << endl;
    return 0;
}
