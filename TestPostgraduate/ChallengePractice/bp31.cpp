#include<cstdio>
#include<cstring>
int n,k,m,s,t;
int culture[105],tol[105][105],road[105][105];
int sig[105]={0},sum=0,min=999999,cs[105]={0};//sig记录已经走过的国家
int check(int x,int y){
	if(road[x][y]>1000)//如果国家x与y之间没有路径
		return 0;
	for(int i=1;i<=cs[0];i++)
		if(tol[culture[x]][culture[i]])//如果国家x的文化排斥国家i的文化
			return 0;
	return 1;
}
void dfs(int x){
	if(sum>min)//剪枝，降低数据量
		return;
	if(x==t){
		if(sum<min)
			min=sum;
		return;
	}
	for(int i=1;i<=n;i++)
		if(check(i,x)&&!sig[i]){
			sum+=road[x][i];
			sig[i]=1;
			cs[++cs[0]]=culture[i];
			dfs(i);
			sum-=road[x][i];
			cs[0]--;
			sig[i]=0;
		}
}
int main(){
	scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&culture[i]);
	for(i=1;i<=k;i++)
		for(j=1;j<=k;j++)
			scanf("%d",&tol[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			road[i][j]=1005;
	for(i=1;i<=m;i++){
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		if(d<road[u][v]){
			road[u][v]=d;
			road[v][u]=d;
		}
	}
	sig[s]=1;
	cs[0]++;
	cs[cs[0]]=culture[s];
	dfs(s);
	if(min==999999)//无解
		printf("-1\n");
	else
		printf("%d\n",min);
	return 0;
}