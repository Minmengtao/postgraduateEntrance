#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int sumNum(int *num,int n);
int main(){
	int k,*num;
	while(scanf("%d",&k)!=EOF){
		int n=(int)(sqrt(2*k+0.25)-0.5);
		num=(int*)malloc(sizeof(int)*n);
		int i;
		for(i=0;i<n;i++)
			num[i]=i+1;
		i=0;
		while(sumNum(num,n)<k&&i<n){
			num[n-i-1]++;
			i++;
		}
		for(i=0;i<n-1;i++)
			printf("%d,",num[i]);
		printf("%d\n",num[i]);
	}
	return 0;
}
int sumNum(int *num,int n){
	int i,sum=0;
	for(i=0;i<n;i++)
		sum+=num[i];
	return sum;
}
