#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,*num,i,j,sum=0;
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	if(n==1)
		sum=num[0];
	while(n>=2){
		for(i=0;i<n;i++)
			for(j=i;j<n;j++)
				if(num[i]<num[j]){
					int temp=num[i];
					num[i]=num[j];
					num[j]=temp;
				}
		num[n-2]=num[n-1]+num[n-2];
		sum+=num[n-2];
		n--;
	}
	printf("%d\n",sum);
	return 0;
}