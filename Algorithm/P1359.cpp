#include<iostream>
#include<math.h>

using namespace std;

int p[6]={1,2,3,5,7,9};
int n;
bool prime( int x ){
    if( x == 1 ) return false;
    for(int i = 2;i <= sqrt( x ); i++ ){
        if(x%i==0)return false;
    }
    return true;
}

void work( int num, int step ){
    if(prime(num)){
        if( step == n ){
            cout << num << endl;
            return;
        }
        else{
            for(int i = 0; i< 6; i++ )
                work( num * 10 + p[ i ], step + 1 );
        }
    }
    else return;
}

int main(){
    cin >> n;
    for(int i = 0; i< 6; i++ )
        work( p[ i ], 1 );
    return 0;
}
