#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int n;
string st;
int num[ 10 ][ 10010 ];

int main(){
    cin >> n;
    for( int j = 0; j < 3; j++ ){//input
        cin >> st;
        for( int i = 0; i < n; i++ ){
            num[ j ][ i ] = st[ i ] - 'a';
        }
    }
    int flag = 0;
    for( int i = 0; i < 3; i++ ){//ö�ٷ�ת���ַ���
        int j = ( i + 1 ) % 3;
        int k = 3 - i - j;
        for( int l = 0; l < n ; l++ ){//��ת
            num[ 3 ][ l ] = num[ i ][ n - l - 1 ];
        }
        for( int x = -6; x <= 6; x++ ){//ö��k
            int conet = 0;
            for( int l = 0; l < n; l++ ){//�ɴ��������ƶ�x���ַ�
                num[ 4 ][ l ] = ( num[ 3 ][ l ] + 26 + x ) % 26;
                num[ 5 ][ l ] = ( num[ 3 ][ l ] + 26 - x ) % 26;
                if( num[ 4 ][ l ] == num[ j ][ l ] && num[ 5 ][ l ] == num[ k ][ l ] ) conet++;
            }
            if( conet == n ){//nλȫ����������
                flag = 1;
                break;
            }
        }
        if( flag ){//output
            for( int l = 0; l < n; l++ )
                cout << char( num[ 3 ][ l ] + 'a' );
            cout << endl;
            break;
        }
    }
    return 0;
}
