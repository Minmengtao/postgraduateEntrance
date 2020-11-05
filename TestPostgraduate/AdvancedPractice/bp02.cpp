#include<stdio.h>
int main(){
	int n;
	__int64 sum;
	scanf("%d\n",&n);
	if(n>=1&&n<10000)
		sum=n*(n+1)/2;
	printf("%I64d\n",sum);
	return 0;
}