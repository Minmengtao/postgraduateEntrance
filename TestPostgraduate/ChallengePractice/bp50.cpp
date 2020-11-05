#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int rel[105][105]={{0}};
int state[105][105]={{0}};
int num=105,n,m;
void dfs(int x,int cls){//x 代表当前安排了多少个人cls代表考场数
	if(cls>num)
		return;
	if(x==n+1){//如果已经安排了n个人，进行判断  
		num=min(num,cls);
		return;
	}
	int j,k;
	for(j=1;j<=cls;j++){//枚举考场
		k=0;
		while(state[j][k]&&!rel[x][state[j][k]])//找到一个空位 并且与该考场人无关系 
			k++;
		if(state[j][k]==0){//满足条件 进行下一考生 
			state[j][k]=x;
			dfs(x+1,cls);
			state[j][k]=0;
		}
	}//回溯 
	state[j][0]=x;
	dfs(x+1,cls+1);// 如果所有房间都不满足条件 增加房间 
	state[j][0]=0;//回溯 
}
int main(){
	int x1,x2;
	scanf("%d\n%d",&n,&m);
	for(int i=1;i<=m;i++){ 
		scanf("%d%d",&x1,&x2);
		rel[x1][x2]=rel[x2][x1]=1;
	}
	dfs(1,1);
	printf("%d\n",num);
	return 0;
}