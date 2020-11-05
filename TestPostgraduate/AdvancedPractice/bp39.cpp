#include<stdio.h>
int main(){
	int i=1,count=0;
	__int64 num[10];
	while(count!=10){
		int num1=0,j=i,k=i+1,num2=0;
		while(j!=0){
			num1+=j%10;
			j=(j-j%10)/10;
		}
		while(k!=0){
			num2+=k%10;
			k=(k-k%10)/10;
		}
		if(num1%17==0&&num2%17==0){
			num[count]=i;
			count++;
		}
		i++;
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%I64d\n",num[n-1]);
	}
	return 0;
}