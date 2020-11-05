#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE][MAXSIZE];
int count=0,n,black[9]={0},white[9]={0};
void dfs_black(int x);
int check_black(int r,int l);
void dfs_white(int x);
int check_white(int r,int l);
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&queue[i][j]);
	dfs_black(1);
	printf("%d\n",count);
	return 0;
}
void dfs_black(int x){
    if(x==n+1)
        dfs_white(1);                           //黑色搜索完了搜索白色的 
    for(int i=1;i<=n;i++)
        if(queue[x][i]==1&&check_black(x,i)){       //可以放皇后且允许放置，则向下搜索 
            black[x]=i;
            dfs_black(x+1);
            black[x]=0;                         //还原 
        }
}
int check_black(int r,int l){
    for(int i=1;i<r;i++)
        if(black[i]==l||r-l==i-black[i]||r+l==i+black[i])//分别判断是否在同一列，同一右斜线，同一左斜线，自己画图一下就明白啦 
            return 0;
    return 1; 
}
void dfs_white(int x){                          //搜索白色皇后和搜黑色皇后步骤一样的，就是注意黑皇后已经占了一个位置了！ 
    if(x==n+1)
        count++;                                  // 统计结果 
    for(int i=1;i<=n;i++)
        if(queue[x][i]==1&&check_white(x,i)){
            white[x]=i;
            dfs_white(x+1);
            white[x]=0;
        }
}
int check_white(int r,int l){//r is row,l is column
    if(black[r]==l) 
		return 0;       //黑皇后已经占了这个位置 
    for(int i=1;i<r;i++)
        if(white[i]==l||r-l==i-white[i]||r+l==i+white[i])
            return 0;
    return 1; 
}



