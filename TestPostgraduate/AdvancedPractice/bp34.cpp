#include<stdio.h>
int isNum(int num);
int main(){
	int i,num[68],j=0,n;
	for(i=32;i<100;i++){
		if(isNum(i*i)==1)
			num[j++]=i*i;
	}
	while(scanf("%d",&n)!=EOF){
		if(n<=j)
			printf("%d\n",num[n-1]);
	}
	return 0;
}
int isNum(int num){
	int a[4],i;
	for(i=0;i<4;i++){
		a[i]=num%10;
		num=(num-a[i])/10;
	}
	if(a[0]*a[2]==a[3]+a[1])
		return 1;
	return 0;
}