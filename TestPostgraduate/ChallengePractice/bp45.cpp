#include<stdio.h>
int A[100005],N;
int maxSubsequeneceSum(){
	__int64 ThisSum=0,MaxSum=0;
	int i;
	for(i=0;i<N;i++){
		ThisSum+=A[i];
		if(MaxSum<ThisSum)
			MaxSum=ThisSum;
		else if(ThisSum<0)
			ThisSum=0;
	}
	printf("%I64d\n",MaxSum);
}
int main(){
	while(~scanf("%d",&N)){
		int i,len=0,max=-10001;
		for(i=0;i<N;i++){
			scanf("%d",&A[i]);
			if(A[i]<0)
				len++;
			if(A[i]>max)
				max=A[i];
		}
		if(len==N)
			printf("%d\n",max);
		else
			maxSubsequeneceSum();
	}
	return 0;
}