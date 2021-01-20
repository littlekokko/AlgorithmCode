#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int n;
queue<int> Radiant;
queue<int> Dire;
char st[100];

void check(queue<int> x){
    while(!x.empty()){
        cout << x.front() << " ";
        x.pop();
    }
    cout << endl;
    return;
}

int main(){

    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> st[ i ];
        if( st[ i ] == 'R' ) Radiant.push( i );
        else Dire.push( i );
    }
    while(!Dire.empty() && !Radiant.empty() ){
        if(Dire.front() < Radiant.front() ){
            int k = Dire.front();
            Dire.push( k + n );
        }
        else{
            int k = Radiant.front();
            Radiant.push( k + n);
        }
        Radiant.pop();
        Dire.pop();
    }
    if( Dire.empty() ) cout << "Radiant" << endl;
    else cout << "Dire" << endl;
    return 0;
}
