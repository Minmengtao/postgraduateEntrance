#include<stdio.h>
#include<math.h>
int isPrime(int num);
int main(){
	int a,b,i,j;
	scanf("%d %d",&a,&b);
	for(i=a;i<=b;i++){
		if(isPrime(i))
			printf("%d=%d\n",i,i);
		else{
			int temp=i;
			printf("%d=",temp);
			for(j=2;j<=i/2;j++){
				while(temp%j==0){
					printf("%d",j);
					temp=temp/j;
					if(temp!=1)
						printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
int isPrime(int num){
	if(num==0||num==1)
		return 0;
	else if(num==2)
		return 1;
	else{
		int i=2;
		for(i=2;i<=sqrt(num);i++)
			if(num%i==0)
				return 0;
		return 1;
	}
}