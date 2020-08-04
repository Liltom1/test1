#include <iostream>
using  namespace std;
 
typedef int ElemType;
typedef struct _tag_Sqlist{
    ElemType *elem;
    int length;
}Sqlist;
 
int InitSqlist(Sqlist &L){//初始化线性表
    L.elem = new ElemType[100];
    L.length = 0;
    return 0;
}
 
int CreatSqlist(Sqlist &L, int n){
    if  (L.elem == NULL) return -1;
    cout << "尾插：";
    for (int i = 0; i < n ; ++i) {
        cin >> L.elem[i];
        L.length++;
    }
    return 0;
}

int TraSqlist(Sqlist L){// 遍历
    if (L.elem == NULL) return -2;
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
    return 0;
}
 
int polynomial_add(Sqlist &La, Sqlist &Lb, Sqlist &Lc){// 多项式相加
 
    Lc.elem = new ElemType[100];//建立一个新的Lc
    if (La.length > Lb.length) Lc.length = La.length;
    else Lc.length = Lb.length;
 
    ElemType *pa, *pb, *pa_last, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    pc = Lc.elem;
    pa_last = La.elem + La.length -1;
    pb_last = Lb.elem + Lb.length -1;
    while (pa <= pa_last && pb <= pb_last){
        *pc++ = *pa++ + *pb++;//将多项式系数相加，指针后移
    }
    
    //当少的多项式相加完后，将多的项加到pc后面
    while (pa <= pa_last) *pc++ = *pa++;
    while (pb <= pb_last) *pc++ = *pb++;
    return 0;
}
 
int main(){
    // Pa = 10 + 5x - 4x^2 + 3x^3 + 2x^4
    // Pb = -3 + 8x + 4x^2 - 5x^4 + 7x^5- 2x^6
    // 10 5 -4 3 2
    // -3 8 4 0 -5 7 -2
    Sqlist Pa, Pb, Pc;
    InitSqlist(Pa);
    InitSqlist(Pb);
 
    CreatSqlist(Pa, 5);
    CreatSqlist(Pb, 7);
    polynomial_add(Pa, Pb, Pc);
 
    cout << "Pa: ";
    TraSqlist(Pa);
    cout << "Pb: ";
    TraSqlist(Pb);
    cout << "Pc: ";
    TraSqlist(Pc);
 
    return 0;
}
