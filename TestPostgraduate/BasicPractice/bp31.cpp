#include<stdio.h>
#include<math.h>
int calculate(int);
int IsPrime(int);
int main(){
	int N,i=0,n,count=0;
	scanf("%d\n",&N);
	if(N<100&&N>0)
		while(i<N){
			
			scanf("%d\n",&n);
			if(n>0&&n<1000){
				count=calculate(n);
				printf("%d\n",count);
			}
			i++;
		}

	return 0;
}
int calculate(int n){
	int sum=0,i;
	for(i=2;i<=n;i++)
		if(IsPrime(i)==1)
			sum+=i;
	return sum;
}
int IsPrime(int n){
	int i=2;
	while(i<=sqrt(n)){
		if(n%i==0)
			return 0;
		i++;
	}
	return 1;
}