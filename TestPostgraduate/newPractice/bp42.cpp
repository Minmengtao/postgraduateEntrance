#include<cstdio>
long a,b,n;
int main(){
	scanf("%ld %ld %ld",&a,&b,&n);
	int cnt=0;
	while(a>b)
		a=a-b*(a/b);
	for(long i=2;i<=n+3;i++){
		long x=a*10/b;
		a=a*10-x*b;
		if(i>n)
			printf("%ld",x);
	}
	printf("\n");
	return 0;
}