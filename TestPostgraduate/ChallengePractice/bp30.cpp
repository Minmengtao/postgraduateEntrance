#include<cstdio>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,sum[30],weight[30],goods[20];
bool dfs(int left,int k){
	if(sum[k]<abs(left))	//剩下的砝码都放到右端天平都不能平衡
		return false;
	if(left==0||abs(left)==sum[k])	//天平平衡了或者剩下的砝码都放在右端能平衡
		return true;
	if(k==n)		//用满了n个砝码依然没称出来
		return false;
	if(dfs(left-weight[k],k+1))	//左物右码 
		return true;
	if(dfs(left+weight[k],k+1))	//左物左码 
		return true;	
	if(dfs(left,k+1))		//不放
		return true;	
	return false;
}
int main(){
	int all=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
		all+=weight[i];	
	}
	for(int j=0;j<m;j++)
		scanf("%d",&goods[j]);
	sort(weight,weight+n,greater<int>());
	sum[0]=all;
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]-weight[i-1];//第i个物品到最后一个物品的总重量
	for(int i=0;i<m;i++){
		if(dfs(goods[i],0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}