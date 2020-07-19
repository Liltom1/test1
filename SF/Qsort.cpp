#include <stdio.h>
int a[101],n;//定义全局变量
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if(left > right){
		return;	
	}
    temp = a[left]; //temp中存的就是基准数
    i = left;
    j = right;
    while(i != j) { //先从右边开始找
    	while(a[j] >= temp && i < j){
			j--;	
		}
    	while(a[i] <= temp && i < j){//再找右边的
    		i++; 
		}      
    	if(i < j){//交换两个数在数组中的位置
    		t = a[i];
    		a[i] = a[j];
    		a[j] = t;
    	}
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i-1);//继续处理左边的
    quicksort(i+1, right);//继续处理右边的
}
int main() {
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
    quicksort(1, n); //快速排序调用
    for(i = 1; i < n; i++){
		printf("%d ", a[i]);
	}
    printf("%d\n", a[n]);
    return 0;
}