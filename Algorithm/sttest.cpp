#include<stdio.h>
#include<vector>
using namespace std;

int t = 0, a, b, key;
char ch;
vector<int> ans;

int chars( char x ){
    if( x == ' ' ) return 0;
    if( x <= '9' && x >= '0' ) return 1;
    if( x == '+' || x == '-' || x == '*' || x == '/' ) return 2;
    return 3;
}

int main(){
    while( ch = getchar() ){
        key = chars( ch );
        if( key == 0 ){
            ans.push_back( t );t = 0;
        }
        if( key == 1 ){
            t = t * 10 + ( ch - '0' );
        }
        if( key == 2 ){
            b = ans.back();ans.pop_back();
            a = ans.back();ans.pop_back();
            if( ch == '+' ) t = a + b;
            if( ch == '-' ) t = a - b;
            if( ch == '*' ) t = a * b;
            if( ch == '/' ) t = a / b;
        }
        if( key == 3 ){
            printf("%d\n",t);break;
        }
    }
    return 0;
}
