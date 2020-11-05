#include<cstdio>
int n,m,a[100010],w[105];
long ans[100010];
int main(){
    scanf("%d%d",&m,&n);
    for(int j=1;j<=m;j++){
		scanf("%d",&a[j]);
		w[j]=1;
	}
    ans[1]=1;
    for(int i=2;i<=n+1;i++){
        ans[i]=0x7fffffff;
        for(int j=1;j<=m;j++){
            while(a[j]*ans[w[j]]<=ans[i-1]) 
				w[j]++;
            if(a[j]*ans[w[j]]<ans[i]) 
				ans[i]=a[j]*ans[w[j]];
        }
    }
    printf("%ld\n",ans[n+1]);
    return 0;
}