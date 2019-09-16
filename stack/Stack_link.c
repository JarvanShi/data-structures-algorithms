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

typedef struct SNode
{
  ElemType data;
  struct SNode *next;
}SNode, *LinkStack;

typedef struct
{
  SNode *next;
  SNode *base;
}*HeadNode;

Status InitStack_Link(HeadNode S)
{
  S->next = NULL;
  S->base = NULL;
}

Status StackTop_Link(HeadNode S)
{
  if(S->next == NULL) return ERROR;
  ElemType e;
  e = S->next->data;
  return e;
}

Status StackPush_Link(HeadNode S, ElemType e)
{
  LinkStack s;
  s = (LinkStack) malloc(sizeof(LinkStack));
  s->data = e;
  s->next = S->next;
  S->next = s;
  if(!S->base) S->base = s;
  return OK;
}

Status StackPop_Link(HeadNode S)
{
  if(!S->next) return ERROR;
  ElemType e;
  e = S->next->data;
  S->next = S->next->next;
  return e;
}
