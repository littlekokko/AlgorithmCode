#include<iostream>

using namespace std;

int n,ans;
int nums[20];

int main(){
    cin >> n;
    ans = 0;
    for( int i = 0; i < n; i++ ){
        cin >> nums[ i ];
        ans = ans ^ nums[ i ];
    }
    cout << ans;
    return 0;
}
