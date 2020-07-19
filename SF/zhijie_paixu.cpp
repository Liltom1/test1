#include <stdio.h>
void InsertSort(int A[], int n){
    int i,j;
    for(i=1;i<n;i++){
        if(A[i] < A[i-1]){
            int temp=A[i];                  //记录当前小的数
            for(j=i-1;j>=0 && A[j]>temp;j--){//向前比较，选择插入的位置
                A[j+1] = A[j];              //如果比前面的数小就进行交换
            }
            A[j+1] = temp;
        }
    }
}
int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    int n = sizeof(A) / sizeof(int);
    InsertSort(A, n);
    printf("插入排序结果：");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]); 
        }
    printf("\n"); 
    return 0;
}
