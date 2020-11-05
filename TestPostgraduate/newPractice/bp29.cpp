/*#include<cstdio>
int main(){
	int col,row,a[105][105];
	scanf("%d%d",&row,&col);
	int i=1,j=1;
	for(int x=1;x<=row*col;x++){
		a[i++][j--]=x;
		if(j==0||i==row+1){
			j=i+j;
			i=1;
			if(j>col){
				i=i+j-col;
				j=col;
			}
		}
	}
	for(i=1;i<=row;i++){
		for(j=1;j<=col;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}*/
#include<cstdio>
int main(){
	int col,row,a[105][105];
	scanf("%d%d",&row,&col);
	int i,j;
	for(i=1;i<=row;i++)
		for(j=1;j<=col;j++)
			scanf("%d",&a[i][j]);
		i=1;j=1;
	for(int x=1;x<=row*col;x++){
		printf("%d ",a[i++][j--]);
		if(j==0||i==row+1){
			j=i+j;
			i=1;
			if(j>col){
				i=i+j-col;
				j=col;
			}
		}
	}
	printf("\n");
	return 0;
}