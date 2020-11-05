#include<stdio.h>
#include<math.h>
int isPrime(int x);
int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		int d1,d2,d3,d,count=0;
		for(d1=3;d1<=9;d1=d1+2){
			d=d1;
			if(isPrime(d)==1&&d>=a&&d<=b)
				printf("%d\n",d);
		}
		for(d1=1;d1<=9;d1=d1+2){
			d=d1*10+d1;
			if(isPrime(d)==1&&d>=a&&d<=b)
				printf("%d\n",d);
		}
		for(d1=1;d1<=9;d1=d1+2){
			for(d2=0;d2<=9;d2++){
				d=d1*100+d2*10+d1;
				if(isPrime(d)==1&&d>=a&&d<=b)
					printf("%d\n",d);
			}
		}
		for(d1=1;d1<=9;d1=d1+2){
			for(d2=0;d2<=9;d2++){
				d=d1*1000+d2*100+d2*10+d1;
				if(isPrime(d)==1&&d>=a&&d<=b)
					printf("%d\n",d);
			}
		}
		for(d1=1;d1<=9;d1=d1+2){
			for(d2=0;d2<=9;d2++){
				for(d3=0;d3<=9;d3++){
					d=d1*10000+d2*1000+d3*100+d2*10+d1;
					if(isPrime(d)==1&&d>=a&&d<=b)
						printf("%d\n",d);
				}
			}
		}
	}
	return 0;
}
int isPrime(int x){
	int i=2;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}