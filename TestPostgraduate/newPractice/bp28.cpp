#include<cstdio>
int a[55][55];
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i<=j)
				a[i][j]=i;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i>j)
				a[i][j]=a[j][i];
	for(i=1;i<=n;i++)
		for(j=2*n-1;j>=n;j--)
			a[i][j]=a[i][2*n-j];
	for(i=2*n-1;i>=n;i--)
		for(j=1;j<=2*n-1;j++)
			a[i][j]=a[2*n-i][j];
	for(i=1;i<=2*n-1;i++){
		for(j=1;j<2*n-1;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][j]);
	}
	return 0;
}