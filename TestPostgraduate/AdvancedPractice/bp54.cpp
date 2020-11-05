#include<stdio.h>
int main(){
	int n;
	int s[11]={1,3,5,7,9,11,9,7,5,3,1};
	while(scanf("%d",&n)!=EOF){
		if(n>=1&&n<=7){
			char sign='Z';
			int count=0,i;
			for(i=1;i<=2*n-1;i++){
				if(i==1||i==2*n-1){
					int j;
					for(j=1;j<n;j++)
						printf(" ");
					printf("%c\n",sign-count);
					count++;
				}else{
					int j;
					for(j=1;j<=n-i||j<=i-n;j++)
						printf(" ");
					printf("%c",sign-count);
					count++;
					if(i<=n)
						for(j=1;j<=s[i-2];j++)
							printf(" ");
					else
						for(j=1;j<=s[11+i-2*n+1];j++)
							printf(" ");
					printf("%c\n",sign-count);
					count++;
				}
			}
			printf("\n");
		}
	}
	return 0;
}