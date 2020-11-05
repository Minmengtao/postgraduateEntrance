#include<stdio.h>
__int64 m,n,count=0,coin[10000][10000];//coin[10000][10000]={0},
int main(){
	__int64 i,j,x,y;
	scanf("%I64d %I64d",&n,&m);
	for(x=1;x<=n;x++)
		for(y=1;y<=m;y++)
			for(i=1;x*i<=n;i++)
				for(j=1;y*j<=m;j++)
					coin[i*x][j*y]++;
	for(x=1;x<=n;x++)
		for(y=1;y<=m;y++)
			if(coin[x][y]%2!=0)
				count++;
	printf("%I64d\n",count);
	return 0;
}