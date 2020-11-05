#include<stdio.h>
#include<math.h>
int isPrime(int x);
int main(){
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF){
		int count=0,i;
		for(i=m;i<=n;i++)
			if(isPrime(i)==1)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
int isPrime(int x){
	if(x==1)
		return 0;
	else if(x==2)
		return 1;
	else{
		int i=2;
		for(i=2;i<=sqrt(x);i++)
			if(x%i==0)
				return 0;
		return 1;
	}
}
