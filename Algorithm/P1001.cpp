#include<iostream>
#include<stdio.h>

using namespace std;

int N, p, q, k;
int ans,sum;
char x, y;
string name, j;

int main(){//Ä£Äâ
    cin >> N;
    ans = 0;
    sum = 0;
    for( int i = 0; i < N; i++ ){
        int money = 0;
        cin >> name >> p >> q >> x >> y >> k;
        if( p > 80 && k >= 1 ) money += 8000;
        if( p > 85 && q > 80 ) money += 4000;
        if( p > 90 ) money += 2000;
        if( p > 85 && y == 'Y' ) money += 1000;
        if( q > 80 && x == 'Y' ) money += 850;
        sum += money;
        if( money > ans ){
            ans = money;
            j = name;
        }
    }
    cout << j << endl << ans << endl << sum << endl;
    return 0;
}
