/*#include<stdio.h>
#define Maxsize 21
int n,test[Maxsize][Maxsize];
int signal[Maxsize]={1};
void dfs(int x);
int check(int x);
int main(){
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&test[i][j]);
	dfs(0);
	for(i=0;i<n;i++)
		if(signal[i]==1)
			printf("%d ",i+1);
	printf("\n");
	return 0;
}
void dfs(int x){
	if(x==n)
		return;
	dfs(x+1);
	if(check(x))
		return;
	else{
		signal[x]=0;
		dfs(x+1);
		signal[x]=1;
	}
	return;
}
int check(int x){
	int i,j;
	for(i=0;i<=x;i++)//判断第i个测试第j个的测试结果是否正确
		for(j=0;j<=x;j++){
			if(i==j)
				continue;
			if(signal[i]==1&&((signal[j]==0&&test[i][j]!=0)||(signal[j]==1&&test[i][j]!=1)))
				return 0;
			else
				continue;
		}
	return 1;
}*/
#include <stdio.h>
int n,test[21][21],count[21]={0};
int main (){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&test[i][j]);
            if(test[i][j]==1)
            	count[j]++;   //记录每一列的1 的个数 ，用于判断是否大于n/2 
		}
		
	int flag=0;
	for(i=1;i<=n;i++){
		if(count[i]>n/2){
			if(flag==0){
				printf("%d",i);
				flag=1;
			}
			else
				printf(" %d",i);
		}
	}
	return 0;
}