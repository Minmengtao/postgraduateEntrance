#include<stdio.h>
int n,m[10][10],count=0;
int check(int x,int y){//判断第x行，第y列能不能放棋子
	int i,index;
	if(m[x][y]==2)
		return 0;
	for(i=x-1;i>=1;i--)//判断要放棋子位置第x行的0位置
		if(m[i][y]==0)
			break;
	index=i;
	for(i=x-1;i>index;i--)//判断从右往左数到第一个0时这段区间内有没有放棋子
		if(m[i][y]==2)
			return 0;
	for(i=y-1;i>=1;i--)//判断要放棋子位置第y列的0位置
		if(m[x][i]==0)
			break;
	index=i;
	for(i=y-1;i>index;i--)//判断从下往上数到第一个0时这段区间内有没有放棋子
		if(m[x][i]==2)
			return 0;
	return 1;
}
void dfs(int x,int pos,int sum,int s){//计算至x行，棋盘上一共需要放置s个棋子
	if(x==n+1){
		return;
	}
	if(sum==s){//满足条件的一种情况
		count++;
		return;
	}
	int i,j;
	for(i=pos;i<=n;i++)//判断第x行第i列情况
		if(check(x,i)&&m[x][i]!=0){
			m[x][i]++;
			dfs(x,i+1,sum+1,s);
			m[x][i]--;
		}
	dfs(++x,1,sum,s);
}
int main(){
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&m[i][j]);
	for(i=1;i<=n;i++){//放置i个棋子有多少种情况
		dfs(1,1,0,i);
		printf("%d\n",count);
		count=0;
	}
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,map[9][9],cnt=0;
int check(int xx,int yy)//第x行,第y个位置 
{
	int i,j,t1=0,t2=0;
	if (map[xx][yy] == 2 || map[xx][yy] == 0) //是洞
	  return 1;
	for (i=xx-1; i>=1; i--) //找出0的位置
	{
		if (map[i][yy] == 0)
		{
			t1 = i;
			break;
		 } 
	}
	for (i=xx-1; i>=1; i--)
	{
		if (map[i][yy] == 2)//找出2的位置，2代表是棋子
		{
			t2 = i;
			break;
		}
	}
	if (t2 > t1) //2比0较近，说明不能放
	{
		return 1;
	}
	t1 = t2 = 0;
	for (i=yy-1; i>=1; i--)//同上，找2，和0 的位置
	{
		if (map[xx][i] == 0)
		{
			t1 = i;
			break;
		}
	}
	for (i=yy-1; i>=1; i--)
	{
		if (map[xx][i] == 2)
		{
			t2 = i;
			break;
		}
	}
	if (t2 > t1)
	 return 1; 
	return 0; //可以放
}
void dfs(int ss,int x,int sum,int pos)//放ss个棋子，x行下标，sum个棋子，pos记录下一个循环位置
{
	int i,j,t;
	if (x > n)
	 return ;
	if (sum >= ss)//一种方案
	{
		cnt++;
		return ;
	}
	for (i=pos; i<=n; i++)
	{
		if (check(x,i)) //发送行列，判断是否可以放棋子
		continue;
		t = map[x][i];
		map[x][i] = 2;
		dfs(ss,x,sum+1,i+1);//增加列
		map[x][i] = t;//回溯，恢复原样
	}
	dfs(ss,++x,sum,1);//换行
}
int main()
{
	int i,j; 
	cin>>n;
	for (i=1; i<=n; i++)
	for (j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
	for (i=1; ;i++)
	{
		cnt=0;
		dfs(i,1,0,1);
		if (cnt==0)
		{
			break;
		}
		cout<<cnt<<endl;
	}
	return 0;
 }*/
