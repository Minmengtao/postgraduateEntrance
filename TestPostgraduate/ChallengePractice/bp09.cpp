#include<stdio.h>
#include<stdlib.h>
typedef struct Matrix{
	int *num;
}Matrix;
int main(){
	int N,M,i,j,k,l;
	scanf("%d %d",&N,&M);
	Matrix *m,*m1,*m2;
	m=(Matrix*)malloc(sizeof(Matrix)*N);
	m1=(Matrix*)malloc(sizeof(Matrix)*N);
	m2=(Matrix*)malloc(sizeof(Matrix)*N);
	for(i=0;i<N;i++){
		m[i].num=(int*)malloc(sizeof(int)*N);
		m1[i].num=(int*)malloc(sizeof(int)*N);
		m2[i].num=(int*)malloc(sizeof(int)*N);
		for(j=0;j<N;j++){
			scanf("%d",&m[i].num[j]);
			m1[i].num[j]=m[i].num[j];
		}
	}
	for(l=1;l<M;l++){
		for(i=0;i<N;i++)
			for(j=0;j<N;j++){
				m2[i].num[j]=0;
				for(k=0;k<N;k++)
					m2[i].num[j]+=m1[i].num[k]*m[k].num[j];
			}
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				m1[i].num[j]=m2[i].num[j];
	}
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++)
			printf("%d ",m1[i].num[j]);
		printf("%d\n",m1[i].num[j]);
	}
	return 0;
}