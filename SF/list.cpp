#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MaxSize 100//线性表存储空间的初始分配
//函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASLBLE -1
#define OVERFLOW -2

//Status 是函数的类型，其指是函数结果状态码
typedef int Status;
typedef char ElemType;
typedef struct{
    ElemType *elem;
    int length;//当前长度
}SqList;

Status lnitList_Sq(SqList &L){//创建线性表
    L.elem = new ElemType[MaxSize];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

void DestoryList(SqList &L){//销毁顺序表
    if(L.elem) delete L.elem;//释放存储空间
}

void Clearlist(SqList &L){//清除顺序表
    L.length = 0;
}

int GetLength(SqList L){//获得表长
    return(L.length);
}

int IsEmpty(SqList L){//判断表是否为空
    if(L.length == 0) return 1;
    else return 0;
}

int GetElem(SqList L,int i,ElemType &e){//取出顺序表的某个元素
    if(i<1 || i>L.length) return ERROR;//判断i值是否合理
    e = L.elem[i-1];
    return OK;
}

int LocateElem(SqList L,ElemType e){//查找元素
    for(int i=0;i<L.length;i++){
        if(L.elem[i] == e) return i+1;
    }
    return 0;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e){//插入元素
    if(i<1||i>L.length) return ERROR;
    if(L.length == MaxSize) return ERROR;
    for(int j=L.length-1;j>=i-1;j--){
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

Status ListDelet_Sq(SqList &L,int i){//删除元素
    if(i<1||i>L.length) return ERROR;
    for(int j=i;j<L.length-i;i++){
        L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return OK;
}
