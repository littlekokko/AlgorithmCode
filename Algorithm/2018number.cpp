#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
int dp[12][5];
int digit[12];
const int a2018[4] = {2, 0, 1, 8};
int dfs(int pos, int i, bool limit) {
    if(pos==-1) {
        return i == 4;
    }
    if(!limit && dp[pos][i]!=-1) {
        return dp[pos][i];
    }
    int ans = 0;
    int up = limit? digit[pos] : 9;
    for(int j = 0; j <= up; ++ j) {
        if(j == a2018[i]) {
            ans += dfs(pos-1, i+1, limit&(j==up));
        }
        else {
            ans += dfs(pos-1, i, limit&(j==up));
        }
    }
    if(!limit) {
        dp[pos][i] = ans;
    }
    return ans;
}
int f(int n) {
    int len = -1;
    while(n) {
        digit[++len] = n%10;
        n /= 10;
    }
    return dfs(len, 0, true);
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, -1, sizeof(dp));
        printf("%d\n", f(n));
    }
    return 0;
}
