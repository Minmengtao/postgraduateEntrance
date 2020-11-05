#include<stdio.h>
int isOdd(int N);
int main(){
	int N;
	scanf("%d\n",&N);
	int i;
	for(i=2;i<=N;i++){
		if(isOdd(i)==1)
			printf("%d\n",i);
	}
	return 0;
}
int isOdd(int N){
	int count=0,i;
	for(i=1;i<N;i++){
		if(N%i==0)
			count+=i;
	}
	if(count==N)
		return 1;
	else
		return 0;
}