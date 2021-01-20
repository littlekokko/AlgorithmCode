#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct cont{
    int s,w,x;
};

bool cmp(cont a,cont b){
    if( a.s == b.s && a.x < b.x ) return true;
    if( a.s > b.s ) return true;
    return false;
}

cont num[200050];
cont win[200050],lose[200050];
int n,r,q;
int winn,losen;

void gb(){//�鲢�������,����������ʤ���������ֱ�����
    int alln = 0;
    int winx = 0;
    int losex = 0;
    while( ( winx < winn ) && ( losex < losen ) ){
        if( cmp( win[ winx ] , lose[ losex ] ) )//ֱ����д�õ�cmp�жϴ�С
            num[ alln++ ] = win[ winx++ ];
        else
            num[ alln++ ] = lose[ losex++ ];
    }
    if( winx == winn )// �����黹��Ԫ��
        while( losex < losen )
            num[ alln++ ] = lose[ losex++ ];
    if( losex == losen )// ʤ���黹��Ԫ��
        while( winx < winn )
            num[ alln++ ] = win[ winx++ ];
    return;
}

int main(){//�鲢����, ��һ����sort,��ʮ������190ms
    scanf("%d%d%d",&n,&r,&q);
    n *= 2;
    for( int i = 0; i < n; i++ )
        num[ i ].x = i + 1;
    for( int i = 0; i < n; i++ )
        scanf("%d",&num[ i ].s);
    for( int i = 0; i < n; i++ )
        scanf("%d",&num[ i ].w);
    sort( num , num + n , cmp );
    for( int j = 0; j < r; j++ ){
        winn = 0;
        losen = 0;
        for( int i = 0; i < n; i += 2 ){//���б���, win[] = ʤ����, lose[] = ������
            if( num[ i ].w > num[ i + 1].w ){
                num[ i ].s++;
                win[ winn++ ] = num[ i ];
                lose[ losen++ ] = num[ i + 1];
            }
            else{
                num[ i + 1 ].s++;
                win[ winn++ ] = num[ i + 1 ];
                lose[ losen++ ] = num[ i ];
            }
        }
        gb();
        /*ÿ�ֽ���������
        cout << "----" << j << "-------"<<endl;
        for(int i = 0; i < n; i++){
            cout << num[i].x << "; s=  "<< num[i].s << "; w= " <<num[i].w<<endl;
        }*/
    }
    printf("%d\n",num[ q - 1 ].x);
    return 0;
}
