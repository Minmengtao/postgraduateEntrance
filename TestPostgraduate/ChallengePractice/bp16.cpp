#include<stdio.h>
int queue[9][9],n=8,max=0,sum=0;
int sign[9]={0};
void dfs(int x);
int check(int row,int column);
int main(){
	int i,j;
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
			scanf("%d",&queue[i][j]);
	dfs(1);
	printf("%d\n",max);
	return 0;
}
void dfs(int x){
	if(x==n+1){
		if(sum>max)
			max=sum;
		return;
	}
	int i;
	for(i=1;i<=n;i++)
		if(check(x,i)){
			sum+=queue[x][i];
			sign[x]=i;
			dfs(x+1);
			sum-=queue[x][i];
			sign[x]=i;
		}
}
int check(int row,int column){
	int i;
	for(i=1;i<row;i++)
		if(sign[i]==column||row+column==i+sign[i]||row-column==i-sign[i])
			return 0;
	return 1;
}
