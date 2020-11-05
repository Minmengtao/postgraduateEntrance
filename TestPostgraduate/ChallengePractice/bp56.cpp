#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Node{
	int sig[10005];
	int top;
}Node;
Node node[10005];
long n,m;
int num[4],len,cnt=0;
int check(){
	if(len==4)
		if(num[0]==num[1]||num[0]==num[2]||num[1]==num[2]||num[3]==num[1]||num[3]==num[2])
			return 0;
	else if(len==3)
		if(num[0]==num[1]||num[0]==num[2]||num[1]==num[2])
			return 0;
	else if(len==2)
		if(num[0]==num[1])
			return 0;
	return 1;
}
void dfs(int x){
	if(len==4&&(num[0]!=num[1]&&num[0]!=num[2]&&num[1]!=num[2]&&num[3]!=num[1]&&num[3]!=num[2])){
		printf("%d->%d->%d->%d\n",num[0],num[1],num[2],num[3]);
		cnt++;
		return;
	}
	for(int j=0;j<node[x].top;j++)
		if(check()&&len<=4){
			num[len++]=node[x].sig[j];
			dfs(node[x].sig[j]);
			len--;
		}
}
int main(){
	scanf("%ld%ld",&n,&m);
	for(int k=1;k<=n;k++)
		node[k].top=0;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		node[a].sig[node[a].top++]=b;
		node[b].sig[node[b].top++]=a;
	}
	for(int j=1;j<=n;j++){
		len=0;
		num[len++]=j;
		dfs(j);
	}
	printf("%d\n",cnt);
	return 0;
}