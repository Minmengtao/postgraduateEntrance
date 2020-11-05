#include<cstdio>
#include<cstring>
#define M 500
int a[20],f[M],ans[20];
int N,K,MAX,g=1<<29;
void DFS(int k,int s){    
	int i,j,t[M];    
	if (k==K){//已经取到了k张邮票        
		if (s>=MAX){//更新最大值
			MAX=s;
			memcpy(ans,a,sizeof(int)*20);
		}
		return;    
	}
	memcpy(t,f,sizeof(int)*M);  
	for(i=a[k]+1;i<=s;i++){        
		for (j=0;j<M-i;j++)            
			if (f[j]+1<f[j+i]) 
				f[j+i]=f[j]+1;       
		for (j=s;f[j]<=N;j++);
		a[k+1]=i;       
		DFS(k+1,j);
		memcpy(f,t,sizeof(int)*M);//回溯
	}
}
int main(){ 
	int i;
	scanf("%d%d",&N,&K); 
	a[1]=1;
	for (i=1;i<=N;i++) 
		f[i]=i; 
	for (;i<M;i++) 
		f[i]=g;
	DFS(1,N+1);
	for (i=1;i<K;i++) 
		printf("%d ",ans[i]); 
	printf("%d\nMAX=%d",ans[K],MAX-1);  
	return 0;
}