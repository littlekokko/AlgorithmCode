#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LinkList;


int main()
{
     int j, i;
     int a[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

     //链表初始化
     LinkList *L, *r, *s, *t;
     L = (LinkList *)malloc(sizeof(LinkList));
     L -> next = NULL;

     r = L;//尾插法建立循环链表
     for(i = 0; i < 13; i++){
        s = (LinkList *)malloc(sizeof(LinkList));
        s -> data = a[i];
        r -> next = s;
        r = s;
     }
     r -> next = L -> next;

    s = L;
    while(s -> data != s -> next -> data){
        for(j = 0; j < 4; j++){
            t = s;
            s = t -> next;
        }
        cout << (s -> data) << " ";
        t -> next = s -> next;
        s = t;
     }
     cout << s -> next -> data << endl;
    return 0;
}
