
#include <iostream>
using namespace std;
// 函数结果状态代码
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define MAXSIZE    100
 
// Status 是函数的类型 其值是函数结果状态代码
typedef int Status;
typedef int QElemType;
 
typedef struct Qnode{
    QElemType data;         // 数据域
    struct Qnode *next;
}QNode, *QueuePtr;
 
typedef struct {
    QueuePtr front;         // 头指针
    QueuePtr rear;          // 尾指针
}LinkQueue;
 
// 链队初始化
Status InitQueue(LinkQueue &Q){
 
    Q.front = Q.rear = new QNode;
    if (!Q.front) exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

// 链队的销毁
Status DestroyQueue(LinkQueue &Q){
 
    QNode *p;
    while (Q.front){
        p = Q.front->next;
        delete Q.front;
        Q.front = p;
    }
    cout << "链队已销毁" << endl;
    return OK;
}

// 将元素e入队
Status EnQueue(LinkQueue &Q, QElemType e){
 
    auto p = new Qnode;
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;       // 尾节点指向p
    Q.rear = p;             // 尾节点下移
    return OK;
}
 
// 元素e出队
Status DeQueue(LinkQueue &Q, QElemType &e){
 
    if (Q.rear == Q.front ) return ERROR;   // 空队
    QNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front; // p为尾节点
    delete p;
    return OK;
}
 
// 链队的队头元素
Status GetHead(LinkQueue Q, QElemType &e){
 
    if (Q.front == Q.rear ) return ERROR;
    e = Q.front->next->data;
    return OK;
}
