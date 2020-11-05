#include<cstdio>
int N,v[100005][2]={{0}};//序号为头，v[序号]=尾
int cr;//多出来的边的另一个顶点
int judge(){
	int i;
	for(i=1;i<=N;i++)
		if(v[i][0]==1)
			return 1;
	return 0;
}
int main(){
	int a,b,ch,i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		v[a][0]++;
		v[b][0]++;
		if(v[a][1]==0)
			v[a][1]=b;
		else if(v[b][1]==0)
			v[b][1]=a;
		else
			ch=a;cr=b;
	}
	while(judge()){
		for(i=1;i<=N;i++)
			if(v[i][1]>0&&v[i][0]>0){
				if(v[i][0]==1||v[v[i][1]][0]==1){
					v[i][0]--;
					v[v[i][1]][0]--;
				}
			}
	}
	for(i=1;i<=N;i++)
		if(v[i][0]==2)
			printf("%d ",i);
	printf("\n");
	//dfs(ch);
	return 0;
}
