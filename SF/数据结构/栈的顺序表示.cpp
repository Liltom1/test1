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
typedef char SElemType;
typedef struct{
    SElemType *base;//栈底指针
    SElemType *Top;//栈顶指针
    int stacksize;//栈可用最大容量
}SqStack;

Status linitStack(SqStack &S){//建造一个空栈
    S.base = new SElemType[Maxsize];
    if(!S.base) exit (OVERFLOW);//存储分配失败
    S.Top=S.base;//栈顶指针等于栈底指针
    S.stacksize=Maxsize;
    return OK;
}

Status StackEmpty(SqStack S){//判断栈是否为空
    if(S.Top==S.base){
        return TRUE;
    }
    else{
        return Flase;
    }
}

int StackLength(SqStack L){//栈的长度
    return L.Top - L.base;
}

Status ClearStack(SqStack &S){//清空顺序栈
    if(!S.base) S.Top=S.base;
    return OK;
}

Status DestroyStack(SqStack &S){//销毁顺序栈
    if(S.base){
        delete S.base;
        S.stacksize = 0;
        S.base=S.Top=NULL;
    }
    return OK;
}

Status Push(SqStack &S,SElemType e){//顺序栈的入栈
    if(S.Top-S.base==S.stacksize){//栈满
        return ERROR;
    }
    *S.Top++=e;
    return OK;
}

Status Pop(SqStack &S,SElemType e){//顺序栈的出栈
    if(S.Top == S.base){
        return ERROR;
    }
    e = *--S.Top;
    return OK;
}


