#include<iostream>

using namespace std;

int n, ans;

void work( int x ){
    for( int i = 1; i <= x/2; i++ ){
        ans++;
        work( i );
    }
}

int main(){
    cin >> n;
    ans = 1;
    work( n );
    cout << ans << endl;
    return 0;
}
