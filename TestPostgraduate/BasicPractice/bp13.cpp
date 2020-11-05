#include<stdio.h>
#include <stdlib.h>
int main(){
	int N,i,num1,num2;
	scanf("%d",&N);
	int *num;
	num=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		scanf("%d %d",&num1,&num2);
		num[i]=num1+num2;
	}
	for(i=0;i<N;i++)
		printf("%d\n",num[i]);
	return 0;
}

