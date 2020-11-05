#include<stdio.h> 
//快速指数模运算
long long mod(long long A,long long B,long long P){
	long long c=1;
	A=A%P;
	while(B>0){
		if(B%2==1)
			c=(c*A)%P;
		B/=2;
		A=(A*A)%P;
	}
	return c ; 
}
int main(){
	long long A,B,P;
	scanf("%lld %lld %lld",&A,&B,&P);
	printf("%lld\n",mod(A,B,P));
	return 0;
}
