/*
�߶������Ⱑ����
����������a���ܴ���b��Ҫ�жϲ�������
���������õ���һ�ַ��ε�˼��
�������ǿ���������ṹ��������һ������
struct node
{
    int left,right,maxv,sum;
}
����left��ʾ����˵������ܴﵽ�����ֵ
right��ʾ���Ҷ˵㵽�����ܴﵽ�����ֵ
maxv��������Ҫ��� �������������ܴﵽ�����������ֵ
sum��Ȼ���������������������ĺ���
��������������еĺ���
�����ж�̬�滮��д+O(n)���㷨
�����е�ʱ��ͺ��������ǵ�O(nlogn)�ķ����㷨
���ǿ���ô����ʽ�Ӽ�renew�������½ڵ�ĸ�����Ϣ�ĺ���
tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
tree[o].left=max(tree[o<<1].left,tree[o<<1].sum+tree[o<<1|1].left);
tree[o].right=max(tree[o<<1|1].right,tree[o<<1|1].sum+tree[o<<1].right);
tree[o].maxv=max(tree[o<<1].right+tree[o<<1|1].left,max(tree[o<<1].maxv,tree[o<<1|1].maxv));
��һ��sum���Զ��������˶�֪��
�ڶ���left���ǿ���֪����Ҫ����˵�����
��ô���Ƿ��ηֳ�����  һ����Ҫô�����˵���������û�е����е�
Ҫô����˶˵����쵽�����Ҳ��� �������ʱ��϶�����ѡȡ��ȫ������߼����Ҷ˵�left
������Ҳ��һ���ĵ��� ����Ͳ�׸˵��
���ĸ�maxv���Ǿ��Ǻ�O(nlogn)�㷨��˼·һ����
����֪��һ����������͵������� Ҫô�����ε�����  Ҫô�����Ұ�ε�����
Ҫô���Ǻ�����ҵ�����
��ô���Ƕ�Ӧ�ľ���tree[o<<1].maxv tree[o<<1|1].maxv tree[o<<1].right+tree[o<<1|1].left
Ȼ���ȡ�����ֵ�ͺ���
�������Ǿ�����˽ڵ��ֵ��ά��������
��ô���ǾͿ������߶��������һ��������������
�����Ϊ�����ֻ�ı�һ����
���Ծ��Ǽ򵥵ĵ����޸�����OTZ
Ȼ��ֱ�ӿ�ߣ�ͺ���
ORZ%%%�Ѻ�����
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=500010;
struct node
{
    int left,right,maxv,sum;
}tree[MAXN<<2];
int n,m;

void renew(int o)
{
    tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
    tree[o].left=max(tree[o<<1].left,tree[o<<1].sum+tree[o<<1|1].left);
    tree[o].right=max(tree[o<<1|1].right,tree[o<<1|1].sum+tree[o<<1].right);
    tree[o].maxv=max(tree[o<<1].right+tree[o<<1|1].left,max(tree[o<<1].maxv,tree[o<<1|1].maxv));
}

void change(int o,int l,int r,int a,int c)//cΪ�޸ĵ�ֵ,a��Ҫ�����޸ĵĵ㣬o�ڵ���,l,r��Ӧ�ڵ�����
{
    if(l==r)
    {
        tree[o].left=tree[o].right=tree[o].maxv=tree[o].sum=c;
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)
        change(o<<1,l,mid,a,c);
    else
        change(o<<1|1,mid+1,r,a,c);
    renew(o);
}

node query(int o,int l,int r,int a,int b)//o�ڵ���,l r�ǽڵ��Ӧ����,a,bΪҪ���ҵ�����
{
    if(a<=l&&b>=r) return tree[o];
    int mid=(l+r)>>1;
    if(b<=mid)//��ѯ����ȫ�������
        return query(o<<1,l,mid,a,b);
    else    if(a>mid)//��ѯ����ȫ���Ҷ���
        return query(o<<1|1,mid+1,r,a,b);
    else//���Ҷ��Ӿ��У�������Ҷ�������������£��ٷ���
    {
        node res,res1,res2;
        res1=query(o<<1,l,mid,a,b);
        res2=query(o<<1|1,mid+1,r,a,b);
        res.sum=res1.sum+res2.sum;
        res.left=max(res1.left,res1.sum+res2.left);
        res.right=max(res2.right,res2.sum+res1.right);
        res.maxv=max(res1.right+res2.left,max(res1.maxv,res2.maxv));
        return res;
    }
}

int main()
{
    int x,op,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        change(1,1,n,i,x);
    }
    while(m--)
    {
        cin>>op>>a>>b;
        if(op==1)
        {
            if(a>b)
                swap(a,b);
            printf("%d\n",query(1,1,n,a,b).maxv);
        }
        else
            change(1,1,n,a,b);
    }
    return 0;
}
