#include<stdio.h>
#include<stdlib.h>
int main(){
	int N,L1,L2;
	int *num;
	while(scanf("%d %d %d",&N,&L1,&L2)!=EOF){
		num=(int *)malloc(sizeof(int)*N);
		int i,count=0,max,sum=0;
		for(i=0;i<N;i++){
			scanf("%d",&num[i]);
			count++;
			sum+=num[i];
			if(count==L1)
				max=sum;
		}
		for(i=0;i<=N-L1;i++){
			int j=i;
			sum=0;
			for(j=i;j<=i+L2-1&&j<N;j++){
				sum+=num[j];
				if(max<sum&&j>=i+L1-1)
					max=sum;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}