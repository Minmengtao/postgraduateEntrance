#include<stdio.h>
#include<math.h>
int isPrime(int x);
int main(){
	int num[25],i,j=0,n;
	for(i=1;i<=100;i++)
		if(isPrime(i)==1)
			num[j++]=i;
	scanf("%d",&n);
	while(n--){
		int number;
		scanf("%d",&number);
		if(number>5&&number<101&&number%2==0)
			for(i=0;i<25;i++)
				for(j=i;j<25;j++)
					if(num[i]+num[j]==number){
						printf("%d %d\n",num[i],num[j]);
						i=25;
						j=25;
					}
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