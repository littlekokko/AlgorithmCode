#include<iostream>

using namespace std;

int a, b;

int gcd(int x, int y){
	int z = y;
    while(x % y!=0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int main(){
    cin >> a >> b;
    cout << gcd( a, b )<< endl;
    return 0;
}
