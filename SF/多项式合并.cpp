#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType *data;
    int length;
}Sqlist;

int InitSqlist(Sqlist &L){//初始化顺序表
    L.data=new ElemType[100];
    L.length=0;
    return 0;
}

int CreatSqlist(Sqlist &L, int n){//创建顺序表
    if(L.data==NULL){
        return -1;
    }
    cout<<"请输入多项式系数:"<<endl;
    for(int i=0;i<n;i++){
        cin>>L.data[i];
        L.length++;
    }
    return 0;
}

int TraSqlist(Sqlist L){//遍历多项式系数
    if(L.data==NULL){
        return -2;
    }
    for(int i=0;i<=L.length;++i){
        cout<<L.data[i]<<" ";
    }
    return 0;
}

int polynomial_add(Sqlist &La, Sqlist &Lb, Sqlist &Lc){
    Lc.data=new ElemType[100];
    if(La.length<=Lb.length) Lc.length=Lb.length;
    else Lc.length=Lb.length;

    ElemType *pa,*pb,*pc,*pa_last,*pb_last;
    pa=La.data;
    pb=Lb.data;
    pc=Lc.data;
    pa_last=La.data+La.length-1;
    pb_last=Lb.data+Lb.length-1;
    while(pa<=pa_last&&pb<=pb_last){
        *pc++ = *pa++ + *pb++;
    }
    while(pa<=pa_last) *pc++ = *pa++;
    while(pb<=pb_last) *pc++ = *pb++;
    return 0;
}

int main(){
    //初始化
    Sqlist Pa,Pb,Pc;
    InitSqlist(Pa);
    InitSqlist(Pb);

    //创建多项式
    CreatSqlist(Pa,5);
    CreatSqlist(Pb,7);

    //多项式合并
    polynomial_add(Pa,Pb,Pc);

    //输出
    cout<<"Pa";
    TraSqlist(Pa);
    cout<<"Pb";
    TraSqlist(Pb);
    cout<<"Pc";
    TraSqlist(Pc);
}
