#include<stdio.h>
int isHw(int n,int di);
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if((isHw(n,2)==1&&isHw(n,10)==1)||n==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
int isHw(int n,int di){
	int num[10],i=0,j;
	while(n!=0){
		num[i]=n%di;
		i++;
		n=n/di;
	}
	for(j=0;j<=(i-1)/2;j++)
		if(num[j]!=num[i-1-j])
			return 0;
	return 1;
}
