#include<stdio.h>
#include<math.h>
int isPrime(int num);
int main(){
	int num[20]={1013,1097,1103,1223,1283,1307,1367,1373,1523,1607,1613,1823,1907,1997,2003,2017,2053,2083,2113,2137};
	int n,sig=1000,len=20,i=0;
	//while(i<len){
	//	if(isPrime(sig)==1){
	//		num[i]=sig;
	//		i++;
	//	}
	//	sig++;
	//}
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",num[n-1]);
	}
	return 0;
}
int isPrime(int num){
	int i,j=num,x,count=0;
	if(num==0||num==1||num==4||num==6||num==8||num==9)
		return 0;
	else if(num==2||num==3||num==5||num==7 )
		return 1;
	else{
		while(j!=0){
			x=j%10;
			j=(j-x)/10;
			count++;
		}
		j=num-x*(int)pow(10,count-1);
		if(isPrime(j)==1){
			for(i=2;i<=sqrt(num);i++)
				if(num%i==0)
					return 0;
			return 1;
		}
		else
			return 0;
	}
}
