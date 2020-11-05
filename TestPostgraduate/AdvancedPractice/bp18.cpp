#include<stdio.h>
int main(){
	int n;
	while(scanf("%d\n",&n)!=EOF){
		if(n==1)
			printf("1");
		else{
			int i;
			for(i=1;i<=n;i++)
				printf("%d+",i);
			for(i=n-1;i>1;i--)
				printf("%d+",i);
			printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}