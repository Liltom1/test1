#include <iostream>
using namespace std;
#define MaxQsize 100
//函数结果状态码
#define OK 1
#define Flase 0
#define TRUE 1
#define ERROR 0
#define INFEASLBLE -1
#define OVERFLOW -2

//Status 是函数的类型，其指是函数结果状态码
typedef int Status;
typedef int QElemType;

typedef struct SqQueue{
    QElemType *base;    // 初始化的动态分配存储空间
    int Front;          // 头指针
    int Rear;           // 尾指针
}SqQueue;

// 构造空队列
Status InitQueue(SqQueue &Q){
    Q.base = new QElemType[MaxQsize];    // 分配数组空间
    if (!Q.base) exit(OVERFLOW);
    Q.Front = 0;                        // 头指针 尾指针为0, 队列为空
    Q.Rear = 0;
    return OK;
}

// 求队列长度
int QueueLength(SqQueue Q){
    return ((Q.Rear-Q.Front+MaxQsize)%MaxQsize);
}

// 插入元素e为Q的队尾元素(入队)
Status EnQueue(SqQueue &Q, QElemType e){
 
    if ((Q.Rear+1)%MaxQsize == Q.Front) return ERROR;    // 队满
    Q.base[Q.Rear] = e;         // 新元素加入队尾
    Q.Rear = (Q.Rear+1)%MaxQsize;    // 队尾指针+1
    return OK;
}

// 删除Q的队头元素，用e返回(出队)
Status DeQueue(SqQueue &Q, QElemType &e){
 
    if (Q.Rear == Q.Front) return ERROR; // 队空
    e = Q.base[Q.Front];                // 保存队头元素
    Q.Front = (Q.Front+1)%MaxQsize;  // 队头指针+1
    return OK;
}

// 用e返回Q的队头元素
Status GetHead(SqQueue Q, QElemType &e){
    if (Q.Front == Q.Rear)
        return ERROR;           // 队不能为空
    e = Q.base[Q.Front];        // 返回队头指针元素, 队头指针不变
    return OK;
}

//遍历队列
Status TraverseQueue(SqQueue Q){
 
    if (Q.Front == Q.Rear) return ERROR;
    cout << "遍历队列： ";
    int temp = Q.Front;
    while (temp < Q.Rear){
        cout << Q.base[temp] << " ";
        temp++;
    }
    cout << endl;
    return OK;
}

// 清空队列
Status ClearQueue(SqQueue &Q){
    if (Q.Front == Q.Rear) return ERROR;    // 已经是空表
    Q.Rear = Q.Front;
    cout << "队列已清空" << endl;
    return OK;
}

// 销毁队列
Status DestroyQueue(SqQueue &Q){
    if (!Q.base) return ERROR;
    delete Q.base;
    Q.base = NULL;
    cout << "队列已销毁" << endl;
    return OK;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, 11);
    EnQueue(Q, 22);
    EnQueue(Q, 33);
    int length = QueueLength(Q);
    cout << "队列长度： " << length << endl;
    TraverseQueue(Q);
    QElemType e;
    GetHead(Q,e);
    cout << "队头元素： " << e << endl;
    DeQueue(Q, e);
    cout << "删除队头元素： "  << e << endl;
    TraverseQueue(Q);
    ClearQueue(Q);
    length = QueueLength(Q);
    cout << "队列长度： " << length << endl;
    DestroyQueue(Q);
    return 0;
}
