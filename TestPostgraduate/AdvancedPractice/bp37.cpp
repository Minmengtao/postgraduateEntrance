#include<stdio.h>
#include<stdlib.h>
typedef struct Milk{
	int pi;
	int ai;
}Milk;
int order(Milk *m,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(m[i].pi>m[j].pi){
				Milk temp=m[i];
				m[i]=m[j];
				m[j]=temp;
			}
	return 1;
}
int main(){
	int N,M,i;
	Milk *m;
	scanf("%d %d",&N,&M);
	m=(Milk*)malloc(sizeof(Milk)*M);
	for(i=0;i<M;i++)
		scanf("%d %d",&m[i].pi,&m[i].ai);
	order(m,M);
	int price=0;
	i=0;
	while(N>=m[i].ai){
		price+=m[i].ai*m[i].pi;
		N=N-m[i].ai;
		i++;
	}
	price+=N*m[i].pi;
	printf("%d\n",price);
	return 0;
}