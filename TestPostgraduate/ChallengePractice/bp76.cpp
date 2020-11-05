/*#include<stdio.h>
typedef struct Kid{
	int height;
	__int64 plus;
}Kid;
Kid kid[100005];
int n;
//void Merge(int low,int mid,int high){
//}
int Sort(int low,int high,int index,int flag){//相对于冒泡排序更快，防止运行超时
	if(low<high){
		int mid=(low+high)/2;
		Sort(low,mid);
		Sort(mid+1,high);
		Merge(low,mid,high);
	}
	int i,count=0;
	if(flag==0)
		for(i=low;i<=high;i++)
			if(kid[i].height>kid[index].height)
				count++;
	if(flag==1)
		for(i=low;i<=high;i++)
			if(kid[i].height<kid[index].height)
				count++;
	return count;
}
int main(){
	scanf("%d",&n);
	int i;
	__int64 sum=0;
	for(i=0;i<n;i++){
		scanf("%d",&kid[i].height);
		kid[i].plus=0;
	}
	for(i=0;i<n;i++)
		kid[i].plus=Sort(0,i,i,0)+Sort(i,n-1,i,1);
	for(i=0;i<n;i++)
		sum+=(kid[i].plus+1)*kid[i].plus/2;
	printf("%I64d\n",sum);
	return 0;
}*/
#include<cstdio>
#include<cstring>
#include<iostream> 
#define maxn 100005 
#define MAXN 1000005
using namespace std;
 
int c[MAXN],  a[MAXN];
__int64 b[maxn];
int n;
 
//获取最小比特 
int lowbit(int x){
	return x & (-x);	
}
 
//获取前x项和
int getSum(int x){
	int s = 0,i;
	for(i = x; i; i -= lowbit(i))
		s += c[i];
	return s;
} 
 
//修改更新 
void add(int x, int val){
	int i;
	for(i= x; i < MAXN; i += lowbit(i)){
		c[i] += val;
	}
}
 
int main(){
	scanf("%d",&n);
	//左边逆序对 
	memset(c,0,sizeof(c));
	int i;
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		add(a[i] + 1, 1);
		b[i] = (i + 1) - getSum(a[i] + 1);
	}
	//右边逆序对 
	memset(c, 0, sizeof(c));
	for(i = n-1; i >= 0; i--){
		add(a[i] + 1, 1);
		b[i] += getSum(a[i]);
	}
	__int64 ans = 0;
	for(i=0; i<n; i++){
		ans += (1 + b[i]) * b[i] / 2;
	}
	printf("%I64d\n",ans);
	return 0;
}