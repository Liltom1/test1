#include<iostream>
#include<cstring>
int a[1500]; 
using namespace std;
void hebing(int *a,int l,int mid,int r)//合并
{
	int b[1500];//临时存放合并结果的数组
	memset(b,0,sizeof(int)) ;//清零b数组
	int k=0;
	int i=l;int j=mid;
	while(i<mid&&j<=r){//当mid的左右两端都剩数字时，任意一边放完了都会退出
		if(a[i]<=a[j]){//小的往前放
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(j<=r){
		b[k++]=a[j++];
	}
	while(i<mid){
		b[k++]=a[i++];//把剩下的没放完的一边放进b里面
	}
	for(int i=l;i<=r;i++){
		a[i]=b[i-l];//把b给a
	}
}

void guibing(int *a,int start,int end){//拆分
	if(start==end) return;//拆到最小不能再拆
	int mid=(start+end)/2;
	guibing(a,start,mid);//拆左边
	guibing(a,mid+1,end);//拆右边
	hebing(a,start,mid+1,end);//合并
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	guibing(a,1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
 } 
