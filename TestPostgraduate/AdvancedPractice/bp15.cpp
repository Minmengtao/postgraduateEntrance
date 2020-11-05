#include<stdio.h>
int main(){
	int s,n;
	while(scanf("%d %d\n",&s,&n)!=EOF){
		int i,j,sign=s;
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				printf("%d",sign);
				if(i!=j)
					printf(" ");
				if(sign>=1&&sign<9)
					sign++;
				else
					sign=1;
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}