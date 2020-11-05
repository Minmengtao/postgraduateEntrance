#include<stdio.h>
#include<stdlib.h>
int main(){
	int M,N;
	int *num;
	while(scanf("%d %d",&M,&N)!=EOF){
		num=(int *)malloc(sizeof(int)*M);
		int i=0,sum=0,max,min;
		while(i<M){
			scanf("%d",&num[i]);
			if(i<N)
				sum+=num[i];
			i++;
		}
		max=sum;min=sum;
		sum=0;i=0;
		int count=0,flag=0;
		while(flag!=2){
			sum+=num[i];
			if(i==N-1)
				flag++;
			count++;
			if(count%N==0){
				if(sum>max)
					max=sum;
				if(sum<min)
					min=sum;
				int sign;
				if(i<N-1)
					sign=M-N+i+1;
				else
					sign=i+1-N;
				sum=sum-num[sign];
				count--;
			}
			i=(i+1)%M;
		}
		printf("Max=%d\nMin=%d\n\n",max,min);
	}
	return 0;
}