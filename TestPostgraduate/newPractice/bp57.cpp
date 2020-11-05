#include<cstdio>
#include<cmath>
int n;
int isprime(int x){
	if(x==3)
		return 1;
	else{
		for(int i=3;i<=sqrt(x);i+=2)
			if(x%i==0)
				return 0;
		return 1;
	}
}
int main(){
	int a[10005],len=0;
	for(int i=3;i<=100000;i+=2)
		if(isprime(i)&&isprime(i+2))
			a[len++]=i+2;
	//printf("%d\n",len);
	while(~scanf("%d",&n)){
		if(n<0)
			break;
		else if(n<=4)
			printf("0\n");
		else
			for(int j=0;j<len-1;j++)
				if(a[j]<=n&&a[j+1]>n){
					printf("%d\n",j+1);
					break;
				}
	}
	return 0;
}