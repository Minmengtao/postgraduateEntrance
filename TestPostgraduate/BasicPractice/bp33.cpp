#include<stdio.h>
int main(){
	int i,j,n;
	scanf("%d",&n);
	if(n>=1&&n<=9){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				printf("%4d",i*j);
			printf("\n");
		}
		printf("\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				if(i>=j)
					printf("%4d",i*j);
			printf("\n");
		}
		printf("\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i<=j)
					printf("%4d",i*j);
				else
					printf("    ");
			}
			printf("\n");
		}
	}
	return 0;
}