#include<cstdio>
int a[25][25],n;
int main(){
	scanf("%d",&n);
	int x=1,y=1;
	for(int i=1;i<=n*n;i++){
		a[x][y]=i;
		if(x%2)
			y++;
		else
			y--;
		if(x%2==1&&y==n+1){//到达最右边边
			x++;
			y--;
		}
		else if(x%2==0&&y==0){//到达最右边
			x++;
			y++;
		}
	}
	for(int j=1;j<=n;j++){
		int k;
		for(k=1;k<n;k++)
			printf("%3d ",a[j][k]);
		printf("%3d\n",a[j][k]);
	}
	return 0;
}