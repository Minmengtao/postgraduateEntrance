#include<cstdio>
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	while(m--){
		int a[15][15],x,i,j;
		int sum=0,div=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				scanf("%d",&x);
				a[i][j]=x;
			}
		for(i=1;i<=n;i++){
			sum+=a[i][i]*a[n+1-i][i];
			div+=(int)a[i][i]/a[n+1-i][i];
		}
		printf("%d %d\n",sum,div);
	}
	return 0;
}
