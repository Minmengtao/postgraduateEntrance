/*#include<stdio.h>
int n,k,T,num[1000005]={1};
int main(){
	scanf("%d %d %d",&n,&k,&T);
	int i=1,count=-1,zz=0;
	long int sum=0;
	while(i<=n){
		count++;
		if(num[i-1]+count<k)
			num[i]=num[i-1]+count;
		else
			num[i]=(num[i-1]+count)%k;
		//printf("%d ",num[i]);
		if(i==1){
			zz++;
			sum+=num[i];
			if(zz==T)
				break;
		}
		else if(i==n){
			num[0]=num[i];
			i=1;
			continue;
		}
		i++;
	}
	printf("\n%ld\n",sum);
	return 0;
}*///ÔËÐÐ³¬Ê±
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	__int64 n,k,T;
	__int64 count=1,sum=1,ans=1,last;
	scanf("%I64d%I64d%I64d",&n,&k,&T);
	if(T==1)
		printf("1\n");
	else{
		for(__int64 i=2;i<=T;i++){
			last=(ans+n*count+n*(n-1)/2)%k;
			ans=last;
			sum+=last;
			//printf("%d %d\n",last,count+n-1);
			count+=n;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}