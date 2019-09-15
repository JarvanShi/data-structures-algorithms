#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct DbNode
{
    ElemType data;
    struct DbNode *prior;
    struct DbNode *next;
}DbNode, *DbLinkList;

typedef struct
{
    ElemType length;
    struct DbNode *prior;
    struct DbNode *next;
}*HeadNode;

Status ListLocate_DbLink(HeadNode L, int i)
{
    DbLinkList p;
    ElemType e;
    int j;
    p = L->next;
    j = 1;
    while(p != L && j<i){
        p = p->next;
        ++j;
    }
    if(p==L || j>i) return ERROR;
    e = p->data;
    return OK;
}//Listlocate_DbLink

Status ListInsert_DbLink(HeadNode L, int i, ElemType e)
{
    DbLinkList p, s;
    int j;
    p = L->next;
    j = 1;
    while(p!=L && j<i){
        p = p->next;
        ++j;
    }
    if(p == L || j>i) return ERROR;
    s = (DbLinkList) malloc(sizeof(DbLinkList));
    s->data = e;
    s->next = p;
    s->prior = p->prior;
    p->prior->next = s;
    p->prior = s;
    ++L->length;
    return OK;
}//ListInsert_DbLink

Status ListDelete_DbLink(HeadNode L, int i)
{
    DbLinkList p;
    ElemType e;
    int j;
    p = L->next;
    j = 1;
    while(p != L && j<i){
        p = p->next;
        ++j;
    }
    if(p == L || j>i) return ERROR;
    e = p->data;
    p->next->prior = p;
    p->prior->next = p->next;
    --L->length;
    return OK;
}
