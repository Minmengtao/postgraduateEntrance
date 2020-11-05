#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	__int64 a[20],next;
	int i=2,n,level=20;
	a[0]=1;a[1]=1;
	while(i<level){
		next=a[i-1]+a[i-2];
		a[i]=next;
		i++;
	}
	while(scanf("%d\n",&n)!=EOF){
		if(n<=level)
			printf("%I64d\n",a[n-1]);
	}
	return 0;
}