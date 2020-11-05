#include<stdio.h>
int main(){
	int n;
	while(scanf("%d\n",&n)!=EOF){
		int i,sum=0;
		for(i=1;i<=n;i++)
			if(n%i==0)
				sum+=i;
		printf("%.2f\n",(double)sum/n);
	}
	return 0;
}