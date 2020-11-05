#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int *num;
	while(scanf("%d",&n)!=EOF){
		num=(int *)malloc(sizeof(int)*n);
		int i,count=0,sum,j;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=0;i<n;i++){
			sum=0;
			for(j=i;j<n;j++){
				sum+=num[j];
				if(sum%11==0){
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
