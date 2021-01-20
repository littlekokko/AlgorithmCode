#include<iostream>
#include<string.h>
using namespace std;

struct e{
    char a;
    int b;
    char c[10];
}p;

int main(){
    int l = sizeof(p);
    cout << l << endl;
    return 0;
}
