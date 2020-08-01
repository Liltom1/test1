#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
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

typedef struct LNode{//声明结点的类型和指向节点的指针类型
    ElemType data;      //节点的数据域
    struct LNode *next; //节点的指针域
}LNode,*LinkList;   //LinkList为指向结构体Lnode的指针类型

Status linitList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return OK;
}

int IsEmpty(LinkList L){//判断链表是否为空
    if(L->next){
        return 0;
    }
    else{
        return 1;
    }
}

Status DestroyLis_L(LinkList &L){//如何销毁单链表
    LNode *p;
    while(L){
        p=L;
        L=L->next;
        delete p;
    }
    return OK;
}

Status ClearList(LinkList &L){//将L重置为空表
    LNode *p;
    LNode *q;
    p=L->next;
    while(p){//没到表尾
    q=p->next;
    delete p;
    p=q;
    }
    L->next=NULL;//头节点指针域为空
    return OK;
}

int ListLength_L(LinkList L){//求出链表长
    LinkList p;
    p=L->next;
    int i=0;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

Status GetElem_L(LinkList L,int i,ElemType &e){//获取线性表中的某个元素，通过变量e返回
    LinkList p;
    p=L->next;//初始化
    int j=1;
    while(p&&j<i){//向后扫描，直到p指到第i个元素或空
        p=p->next;
        j++;
    }
    if(!p||j>i){//第i个元素不存在
        return ERROR;
    }
    e=p->data;//去第i个元素
    return OK;
}

LNode *LocateElem_L(LinkList L,ElemType e){//查找元素r找到之后返回地址
    LinkList p;
    p=L->next;
    while(p&&p->data!=e){
        p=p->next;
    }
    return p;
}

int LoacateElem_L1(LinkList L,ElemType e){//查找元素r找到之后返回位置序号
    LinkList p;
    p=L->next;
    int j=1;
    while(p&&p->data!=e){
        p=p->next;
        j++;
    }
    if(p) return j;
    else return 0;//返回0查找失败
}

Status Listsert_L(LinkList L,int i,ElemType e){//在L中第i个元素之前插入数据元素e
    LinkList p;
    LNode *s;
    int j=0;
    while(p&&j<i-1){//寻找第i-1个节点，p指向i-1
        p=p->next;
        ++j;
    }
    if(p || j>i-1){//i大于表长+1或者小于1，插入位置非法
        return ERROR;
    }
    s=new LNode; //生成新节点s，将节点s的数据域置为e
    if(s=NULL){
        cout<<"out of space!"<<endl;
    }
    s->data=e;
    s->next=p->next;//将结点s插入L中
    p->next=s;
    return OK;
}

Status ListDelete(LinkList &L,int i,ElemType &e){
    LinkList p;
    int j=0;
    LNode *q;
    p=L;
    while(p->next&&j<i-1){//寻找第i个节点，并令p指向其前驱
        p=p->next;
        ++j;
    }
    if(p->next&&j>i-1){//删除位置不合理
        return ERROR;
    }
    q=p->next;//临时保存被删除结点的地址以备释放
    e=q->data;//保存删除结点的数据域
    p->next=q->next;//改变删除节点前驱结点的指针域（*重要）
    delete q;//释放删除结点的空间
    return OK;
}

void CreateList_H(LinkList &L,int n){//头插法建立链表
    L=new LNode;
    L->next=NULL;//先建立一个带头结点的单链表
    LNode *p;
    for(int i=n;i>0;--i){
        p=new LNode;//生成新节点
        cin>>p->data;//输入元素值
        L->next=p->next;//插入到表头
        L->next=p;
    }
}

void CreateList_L(LinkList &L,int n){//尾插法创建单链表
    L=new LNode;
    L->next=NULL;
    LNode *p;
    LNode *r;
    r=L;//尾指针r指向头结点
    for(int i=n;i>0;++i){
        p=new LNode;
        cin>>p->data;//生成新结点，输入元素
        p->next=NULL;
        r->next=p;//插入到表尾
        r=p;//r指向新的尾结点
    }
}
