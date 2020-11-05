#include<stdio.h>
#include<stdlib.h>
__int64 *BubbleSort(__int64*,int);
int main(){
	int M;
	__int64 *a;
	while(scanf("%d\n",&M)!=EOF){
		a=(__int64*)malloc(M*sizeof(__int64));
		int i=0;
		while(i<M){
			scanf("%I64d\n",&a[i]);
			i++;
		}
		if(M!=1)
			a=BubbleSort(a,M);
		for(i=0;i<M;i++)
			printf("%I64d ",a[i]);
		printf("\n");
		free(a);
	}
	return 0;
}
__int64 *BubbleSort(__int64 *a,int M){
	__int64 temp;
	int i,j;
	for(i=0;i<M-1;i++)
		for(j=i+1;j<M;j++)
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}

	return a;
}