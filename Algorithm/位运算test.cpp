#include<iostream>
using namespace std;

int main(){
    int a=1;
    for(int i = 0; i < 1000000000; i++)
        a = a << 1;
    cout << a;
    return 0;
}
