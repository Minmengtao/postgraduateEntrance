#include<stdio.h>
int n,candy[105],sum=0;
int judge(){
	int i;
	for(i=1;i<n;i++)
		if(candy[i]!=candy[i-1])
			return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	int i,count=0;
	for(i=0;i<n;i++)
		scanf("%d",&candy[i]);
	while(!judge()){
		int temp=candy[0]/2;
		candy[0]/=2;
		for(i=0;i<n-1;i++){
			candy[i]+=(candy[i+1]/2);
			candy[i+1]/=2;
		}
		candy[n-1]+=temp;
		for(i=0;i<n;i++)
			if(candy[i]%2!=0){
				candy[i]++;
				sum++;
			}
	}
	printf("%d\n",sum);
	return 0;
}