/*#include<iostream>
using namespace std;
int main(){
    cout << "hello echo" << endl;
   	//system("pause");
    return 0;
}*/

#include <stdio.h>
void InsertionSort(int A[], int n)
{
for(int i = 1; i < n; i++) {
    int get = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > get){
        A[j + 1] = A[j]; 
        j--;
        }
        A[j + 1] = get;
    }
}
 
int main()
{
int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
int n = sizeof(A) / sizeof(int);
InsertionSort(A, n);
printf("插入排序结果：");
for (int i = 0; i < n; i++){
    printf("%d ", A[i]);
    }
 printf("\n");
 return 0;
} 
