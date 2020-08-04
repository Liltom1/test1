#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define Maxsize 100
//函数结果状态码
#define OK 1
#define Flase 0
#define TRUE 1
#define ERROR 0
#define INFEASLBLE -1
#define OVERFLOW -2
//Status 是函数的类型，其指是函数结果状态码
typedef int Status;
typedef char ElemType;

typedef struct{//创建顺序表
    ElemType *data;
    int length;
}SqList;

Status lnitList_Sq(SqList &L){//为线性表创建空间
    L.data = new ElemType[Maxsize];
    if(!L.data) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

void DestoryList(SqList &L){//销毁顺序表
    if(L.data) delete L.data;
}

void Clearlist(SqList &L){//清除顺序表
    L.length = 0;
}

int GetLength(SqList L){//获得表长
    return(L.length);
}

int IsEmpty(SqList L){//判断是否为空表
    if(L.length == 0) return OK;
    else return 0;
}

int Getdata(SqList L,int i,ElemType &e){//取出顺序表的元素
    if(i<1||i>L.length) return ERROR;
    e=L.data[i-1];
    return 0;
}

int LocateElem(SqList L,ElemType e){//查找元素
    for(int i=0;i<L.length;i++){
        if(e == L.data[i]) return i+1;
    }
    return 0;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e){//顺序表插入元素
    if(i<1||i>L.length+1) return ERROR;
    if(L.length == Maxsize) return ERROR;
    for(int j=L.length-1;j>=i-1;j--){
        L.data[j+1]=L.data[j];
    }
    L.data[i-1]=e;
    L.length++;
    return OK;
}

Status ListDelet_Sq(SqList &L,int i){//删除元素
    if(L.length == 0) return ERROR;
    for(int j=i-1;j<L.length-i;j++){
        L.data[j]=L.data[j+1];
    } 
    L.length--;
    return OK;
}

void union1(SqList &La,SqList Lb){//顺序表合并
    ElemType e;
    int La_len,Lb_Len;
    La_len=GetLength(La);
    Lb_Len=GetLength(Lb);
    for(int i=1;i<=Lb_Len;i++){
        Getdata(Lb,i,e);
        if(!LocateElem(La,e)){
            ListInsert_Sq(La,++La_len,e);
        }
    }
}
