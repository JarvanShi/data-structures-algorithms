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

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue_Link(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if(!Q->front) exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}//InitQueue_Link

Status QueueHead_Link(LinkQueue *Q)
{
    return Q->front->next->data;
}

Status QueueEn_Link(LinkQueue *Q, ElemType e)
{
    QueuePtr p;
    p = (QueuePtr) malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}//QueueEn_Link

Status QueueDe_Link(LinkQueue *Q)
{
    if(Q->front == Q->rear) return ERROR;
    QueuePtr p;
    p = Q->front->next;
    ElemType e;
    e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) Q->rear = Q->front;
    free(p);
    return e;
}//QueueDe_Link
