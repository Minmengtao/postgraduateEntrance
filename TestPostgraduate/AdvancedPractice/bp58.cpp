#include<stdio.h>
#include<stdlib.h>
typedef struct matrix{
	int *num;
}Matrix;
int main(){
	Matrix *m;
	int n;
	while(scanf("%d",&n)!=EOF){
		m=(Matrix*)malloc(sizeof(Matrix)*n);
		int i,j;;
		for(i=0;i<n;i++){
			m[i].num=(int*)malloc(sizeof(int)*n);
			for(j=0;j<n;j++)
				scanf("%d",&m[i].num[j]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d",m[j].num[i]);
				if(j>=0&&j<n-1)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
		free(m);
	}
	return 0;
}