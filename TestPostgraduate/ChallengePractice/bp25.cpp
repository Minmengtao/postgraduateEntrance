#include<stdio.h>
int n,m,r[45]={0};//0表示这个位置可以走，1表示这个位置是陷进
int count=0;//从1到n的方案数
//int check(int x){
//}
void dfs(int x){
	if(x==n){
		count++;
		return;
	}
	for(int i=1;i<=2;i++)
		if(r[x+i]==0&&x+i<=n)
			dfs(x+i);
}
int main(){
	int preloc=-1,loc,flag=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&loc);
		if(loc==preloc+1)
			flag=1;
		preloc=loc;
		r[loc]=1;
	}
	if(flag)
		printf("0\n");
	else{
		dfs(1);
		printf("%d\n",count);
	}
	return 0;
}