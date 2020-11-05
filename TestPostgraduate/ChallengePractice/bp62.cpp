//陷入无穷循环当中，走的路径不能重复，将已走过的路记录下来
#include<cstdio>
int xx[4][2]={{0,1},{1,0},{-1,0},{0,-1}};//位移向量
int n,m,a[12][12],sum=0,cnt=1,total=0,min=100;
int sig[12][12]={{0}};//记录已经走过的路径
int zz=0;
int check(int x,int y,int i){
	if(x+xx[i][0]<1||x+xx[i][0]>n)
		return 0;
	if(y+xx[i][1]<1||y+xx[i][1]>m)
		return 0;
	if(sig[x+xx[i][0]][y+xx[i][1]]==1)
		return 0;
	if((sum+a[x+xx[i][0]][y+xx[i][1]])*2>total)
		return 0;
	return 1;
}
void dfs(int x,int y){
	if(sum*2==total){
		if(cnt<min)
			min=cnt;
		return;
	}
	for(int i=0;i<4;i++){
		if(check(x,y,i)){
			cnt++;
			sig[x+xx[i][0]][y+xx[i][1]]=1;
			/*for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++)
					printf("%d ",sig[j][k]);
				printf("\n");
			}
			printf("\n");*/
			sum+=a[x+xx[i][0]][y+xx[i][1]];
			dfs(x+xx[i][0],y+xx[i][1]);
			sum-=a[x+xx[i][0]][y+xx[i][1]];
			cnt--;
			sig[x+xx[i][0]][y+xx[i][1]]=0;
		}
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			total+=a[i][j];
		}
	sum=a[1][1];sig[1][1]=1;
	dfs(1,1);
	printf("%d\n",min);
	return 0;
}