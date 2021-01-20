#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int x;
    cin >> x ;
    switch(x/10){
        case 1: cout << "1" << endl;break;
        case 2: cout << "2" << endl;break;
        case 3: cout << "3" << endl;break;
        case 4: cout << "4" << endl;break;
        case 5: cout << "5" << endl;break;
        default : cout << "6" << endl;break;
    }
    return 0;
}
