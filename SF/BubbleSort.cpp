#include <stdio.h>
void BubbleSort(int A[], int n)
{
    int i, j;
    int temp;
    for(i=0; i<n; i++){
        bool flag=false;              //表示本趟冒泡是否发生交换的标志
        for(j=1; j<n-i; j++){         //j的起始位置为1，终止位置为n-i  
            if(A[j]<A[j-1]){
               temp=A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
                flag=true;
            }
        }
        if(flag==false)             //未交换，说明已经有序，停止排序
            return;
    }          
}
int main() 
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    int n = sizeof(A) / sizeof(int);
    BubbleSort(A, n);
    printf("插入排序结果：");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]); 
        }
    printf("\n"); 
    return 0;
}
