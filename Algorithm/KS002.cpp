#include<iostream>
#include<algorithm>
using namespace std;

int n, m, sum;
int pre[ 200050 ];
struct node{
    int start,end,power;
} edge[ 200050 ];

int cmp(node a, node b){
    return a.power < b.power;
}
int find(int x){
    if( x != pre[ x ] ) pre[ x ] = find( pre[ x ] );
    return pre[ x ];
}
void merge(int x,int y,int z){
    int fx = find( x );
    int fy = find( y );
    if( fx != fy ){
        pre[ fy ] = fx;
        sum += z;
    }
}
int main(){
    int testn;
    cin >> testn;
    while( testn-- ){
        cin >> n >> m;
        sum = 0;
        int start,end,power;
        for( int i = 1; i <= n; i++ ){
            cin >> power;
            edge[ i ].start = 0;
            edge[ i ].end = i;
            edge[ i ].power = power;
        }
        m = n + m;
        for(int i = n + 1; i <= m; i++){
            cin >> start >> end >> power;
            edge[ i ].start = start;
            edge[ i ].end = end;
            edge[ i ].power = power;
        }
        for(int i = 0; i <= n; i++ )
            pre[ i ] = i;
        sort( edge + 1, edge + m + 1, cmp );
        for(int i = 1; i <= m; i++ )
            merge( edge[ i ].start, edge[ i ].end, edge[ i ].power );
        cout << sum << endl;
    }
    return 0;
}
