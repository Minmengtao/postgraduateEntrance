#include<stdio.h>
int a[10000]={0},n;
int main(){
	int i,j,k,flag=0;
	scanf("%d",&n);
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++){
				if(2*i+2*j+k==n){
					printf("%d\n",i*10000+j*1000+k*100+j*10+i);
					flag=1;
				}
				if(2*i+2*j+k>n)
					break;
			}
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++){
				if(2*i+2*j+2*k==n){
					flag=1;
					printf("%d\n",i*100000+j*10000+k*1000+k*100+j*10+i);
				}
				if(2*i+2*j+2*k>n)
					break;
			}
	if(flag==0)
		printf("-1\n");
	return 0;
}