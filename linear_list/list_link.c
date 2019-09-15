#include<stdio.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

typedef struct
{
    ElemType length;
    LNode *next;
}*HeadNode;

Status ListLength_Link(HeadNode L)
{
    return L->length;
}//ListLength_Link

Status ListLocate_Link(HeadNode L, int i)
{
    // L带头节点的单链表的头指针
    LinkList p;
    ElemType e;
    int j;
    p = L->next;  // 指向第一个节点
    j = 1;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i) return ERROR;  // 第i个元素不存在
    e = p->data;
    return OK;
}//ListLocate_Link

Status ListInsert_Link(HeadNode L, int i, ElemType e)
{
    LinkList p,s;
    int j;
    p = L;  // p指向头节点
    j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }
    if(!p || j>i-1) return ERROR;
    s = (LinkList) malloc(sizeof(LNode));  // 生成新节点
    s->data = e;
    s->next = p->next;
    p->next = s;
    ++L->length;
    return OK;
}//ListInsert_Link

Status ListDelete_Link(HeadNode L, int i)
{
    LinkList p, q;
    ElemType e;
    int j;
    p = L;  // 指向头节点
    j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }
    if(!p || j>i-1) return ERROR;
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    --L->length;
    return OK;
}//ListDelete_Link

Status CreateList_Link(HeadNode L, int n)
{
    LinkList p;
    int i;
    L = (HeadNode) malloc(sizeof(HeadNode));
    L->length = 0;
    L->next = NULL;
    for(i=n; i>0;--i){
        p = (LinkList) malloc(sizeof(LNode));
        scanf(&(p->data));
        p->next = L->next;
        L->next = p;
    }
    L->length = n;
}//CreateList_Link
