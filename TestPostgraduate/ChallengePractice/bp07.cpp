#include<stdio.h>
int An(int n,int k);
int Sn(int n,int k1,int k2);
int main(){
	int n;
	scanf("%d\n",&n);
	//An(n,1);
	Sn(n,1,n);
	printf("\n");
	return 0;
}
int Sn(int n,int k1,int k2){
	if(n==1){
		An(n,1);
		printf("+%d",k1);
		return 1;
	}
	if(k2==0)
		return 0;
	if(k1!=1)
		printf("(");
	Sn(n,k1+1,k2-1);
	An(k2,1);
	printf("+%d",k1);
	if(k1!=1)
		printf(")");
	return 1;
}
int An(int n,int k){
	if(n==1){
		printf("sin(1)");
		return 1;
	}
	if(k==n+1)
		return 0;
	printf("sin(%d",k);
	if(k!=n){
		if(k%2==0)
			printf("-");
		else
			printf("+");
	}
	An(n,k+1);
	printf(")");
	return 1;
}