#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int f[ 10050 ];
    int N;
    memset(f,1,sizeof(f));
    cin >> N;
    for( int i = 0; i < N; ++i ){
        int h = 0;
        int H[ 200 ];
        int connet = 0;
        int sum = 0;
        int g[ 10050 ];
        memset(g,0,sizeof(g));
        g[0]=1;
        cin >> h;
        while( h != -1 ){
            H[connet++]=h;
            sum+=h;
            cin >> h;
        }
        for( int k = 0; k < connet; ++k )
            for( int j = sum; j >= 0; --j ){
                if( j >= H[ k ] && g[j-H[k]])
                    g[j]=1;
            }
        for( int j = 0; j <= 10001; ++j )
            f[j]&=g[j];
    }
    int ans=0;
    for( int i = 10001; i >= 0; i-- )
        if(f[i]){ans=i;break;}
    cout << ans << endl;
    return 0;
}
