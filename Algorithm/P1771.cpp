#include<iostream>
#include<algorithm>
#include<stdio.h>
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
int n,r,q;

int main(){//sort+cmp����sort��ʮ������998ms(��ʱ), stable_sort��ʮ���������700ms
    scanf("%d%d%d",&n,&r,&q);
    n *= 2;
    for( int i = 0; i < n; i++ )
        num[ i ].x = i + 1;
    for( int i = 0; i < n; i++ )
        scanf("%d",&num[ i ].s);
    for( int i = 0; i < n; i++ )
        scanf("%d",&num[ i ].w);
    sort( num , num + n , cmp );
    for( int i = 0; i < r; i++){
        for( int j = 0; j < n; j += 2 ){//���б���
            if( num[ j ].w > num[ j + 1].w ) num[ j ].s++;
            else num[ j + 1 ].s++;
        }
        stable_sort( num , num + n , cmp );//stable_sort:a==bʱ���ύ��a,b��˳��
         /*ÿ�ֽ���������
        cout << "----" << j << "-------"<<endl;
        for(int i = 0; i < n; i++){
            cout << num[i].x << "; s=  "<< num[i].s << "; w= " <<num[i].w<<endl;
        }*/
    }
    printf("%d\n",num[ q - 1 ].x);
    return 0;
}
