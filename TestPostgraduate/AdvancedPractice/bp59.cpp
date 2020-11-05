#include<stdio.h>
#include<stdlib.h>
typedef struct matrix{
	int *num;
}Matrix;
int main(){
	Matrix *m;
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n%2!=0){
			m=(Matrix*)malloc(sizeof(Matrix)*n);
			int i,j;
			for(i=0;i<n;i++)
				m[i].num=(int*)malloc(sizeof(int)*n);
			int row=1;//ÐÐ
			int column=(n+1)/2;//ÁÐ
			int pre_row,pre_column;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					m[i].num[j]=0;
			for(i=1;i<=n*n;i++){
				if(m[row-1].num[column-1]!=0){
					row=pre_row+1;
					column=pre_column;
				}
				m[row-1].num[column-1]=i;
				pre_row=row;
				pre_column=column;
				if(row==1)
					row=n;
				else
					row--;
				if(column==n)
					column=1;
				else
					column++;
			}
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%d",m[i].num[j]);
					if(j>=0&&j<n-1)
						printf(" ");
				}
				printf("\n");
			}
			printf("\n");
			free(m);
		}
	}
	return 0;
}