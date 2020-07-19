#include <stdio.h>
void shellsort(int A[],int n)
{
    int i,j,Increment;
    int Tmp;
    for(Increment = n/2;Increment>0;Increment/=2){
        for(i=Increment;i<n;i++){
            Tmp=A[i];
            for(j=i;j>=Increment;j-=Increment){
            if(Tmp<A[j-Increment]){
                A[j]=A[j-Increment];
                }
            else
            {
                break;
            } 
            }
            A[j]=Tmp;
        }
    }
}
int main() 
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    int n = sizeof(A) / sizeof(int);
    shellsort(A, n);
    printf("插入排序结果：");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]); 
        }
    printf("\n"); 
    return 0;
}
