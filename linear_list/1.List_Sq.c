include<stdio.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1  // 不可行
#define OVERFLOW -2  // 内存溢出

#define INIT_LIST_SIZE 100 // 初始列表的长度
#define LISTINCREMENT 10  // 列表增量

typedef int Status
typedef int ElemType

typedef struct{
    ElemType *elem;  //存储空间基址
    int length;  // 当前列表实际存储长度
    int listsize;  // 当前分配的列表存储长度
}SqList;

Status InitList_Sq(SqList *L){ // 结构体指针作为形参，c不支持引用作为形参
    // 构造空的线性表
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);  // 存储分配失败
    L->length = 0;  // 空表长度为0
    L->listsize = LIST_INIT_SIZE  // 初始存储容量
}// InitList_Sq

Status ListInsert_Sq(SqList *L, int i, ElemType e){
    // 在第i个位置插入元素e
    if(i<1 || i>L->length+1) return ERROR;  // 插入位置不合法
    if(L->length >= L->listsize){
        ElemType *newelem = (ElemType *) malloc((L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newelem) exit(OVERFLOW);  // 存储分配失败
        L->elem = newelem;  // 新的基址
        L->listsize += LISTINCREMENT;  // 列表存储容量增加
    }
    int *p, *q;
    p = &(L->elem[i-1]);  // 插入位置的地址 
    q = L->elem + L->length -1;  // 列表最后一个元素的地址
    for(q; p<=q; --q){  // 小心边界条件
        *(q+1) = *q;
    }
    *p = e;
    ++(L->length);  // 实际存储长度加1
}//ListInsert_Sq

Status ListDelete_Sq(SqList *L, int i){
    // 删除线性表中第i个元素
    if(i<1 || i>L->length) return ERROR;  // 删除位置不合法
    ElemType *p, *q;
    p = &(L->elem[i-1]);  // 删除位置的地址
    q = L->elem + L->length -1;  // 列表最后一个元素的地址
    for(++p;p<=q;++p)
        *(p-1) = *p;
    L->length -= 1;  // 列表实际存储减1
}// ListDelete_Sq
