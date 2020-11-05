#include<stdio.h>
int main(){
	int T,i,j,k=1;
	char s[81][81];
	scanf("%d\n",&T);
	while(k<=T){
		char sign;
		int n;
		scanf("%c %d\n",&sign,&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=2*n-1;j++){
				if(i+j==n+1||i==n)
					s[i][j]=sign;
				else if(j-i==n-1){
					s[i][j]=sign;
					break;
				}
				else
					s[i][j]=' ';
			}
		for(i=1;i<=n;i++){
			for(j=1;j<=2*n-1;j++)
				if(j-i<=n-1)
					printf("%c",s[i][j]);
			printf("\n");
		}
		printf("\n");
		k++;
	}
	return 0;
}