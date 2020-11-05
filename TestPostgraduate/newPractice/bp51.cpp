/*#include<stdio.h>
#include<math.h>
int prime[100],len=0,a[100005]={0};
int isPrime(int x){
	if(x==2||x==3)
		return 1;
	else if(x==1||x==0)
		return 0;
	else{
		for(int i=3;i<=sqrt(x);i+=2)
			if(x%i==0)
				return 0;
		return 1;
	}
}
int main(){
	prime[0]=2;len++;
	for(int i=3;i<=sqrt(100000);i+=2)
		if(isPrime(i))
			prime[len++]=i;
	for(int j=0;j<len;j++)
		for(int k=0;k<len;k++)
			a[prime[j]*prime[k]]=1;
	int x,s;
	scanf("%d",&x);
	while(x--){
		scanf("%d",&s);
		if(a[s])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}*/
#include<cstdio>
int main(){
	int t,a[10005],sum;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<t;i++){
		sum=0;
		for(int j=2;a[i]!=1;j++)
			while(a[i]%j==0){
				a[i]/=j;
				sum++;
			}
		if(sum==2)
			printf ("Yes\n");
		else 
			printf ("No\n");
	}
	return 0;
}
