#include<iostream>

using namespace std;

int main(){
    int time = 8;
    int ans = 0;
    int x,y;
    for( int i = 1; i <= 7; i++ ){
        cin >> x >> y;
        x = x + y;
        if( x > time ){
            time = x;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
