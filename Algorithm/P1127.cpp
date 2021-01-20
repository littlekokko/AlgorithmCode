#include<iostream>

using namespace std;

int ans = 0;
int k;
double sum = 0;

int main(){
    cin >> k;
    while( sum <= k )   sum += 1.0/++ans;
    cout << ans << endl;
    return 0;
}
