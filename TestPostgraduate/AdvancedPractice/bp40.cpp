#include<stdio.h>
#include<stdlib.h>
int order(int *num,int n);
int main(){
	int n,*num;
	while(scanf("%d",&n)!=EOF){
		num=(int*)malloc(sizeof(int)*n);
		int i,j=0;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		order(num,n);
		for(i=1;i<n;i++){
			if(num[j]!=num[i]){
				j++;
				num[j]=num[i];
			}
		}
		for(i=0;i<j;i++)
			printf("%d ",num[i]);
		printf("%d\n",num[i]);
	}
	return 0;
}
int order(int *num,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(num[i]>num[j]){
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
	return 1;
}