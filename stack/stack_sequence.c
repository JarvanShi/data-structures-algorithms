#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef int ElemType;

typedef struct
{
  ElemType *base;
  ElemType *top;
  int stacksize;
}SqStack;

Status InitStack_Sq(SqStack *S)
{
  S->base = (ElemType *) malloc(sizeof(ElemType) * STACK_INIT_SIZE);
  if(!S->base) exit(OVERFLOW);
  S->top = S->base;
  S->stacksize = STACK_INIT_SIZE;
  return OK;
}

Status StackTop_Sq(SqStack *S)
{
  ElemType e;
  if(S->top == S->base) return ERROR;
  e = *(S->top-1);
  return e;
}

Status StackPush_Sq(SqStack *S, ElemType e)
{
  if(S->top - S->base >= S->stacksize){
    S->base = (ElemType *) realloc(S->base, sizeof(ElemType) * (STACK_INIT_SIZE + STACKINCREMENT));
    S->top = S->base + STACKINCREMENT;
    }
  *(s->top++) = e;
  ++S->stacksize;
  return OK;
}

Status StackPop_Sq(SqStack *S)
{
  if(S->top == S->base) return ERROR;
  ElemType e;
  e = *(--S->top);
  return e;
}
    
