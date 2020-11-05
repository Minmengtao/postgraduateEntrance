#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("5\n");
		else{
			int num1=5,num2,i=3;
			while(i<=n){
				num2=num1+(i-3)*3+7;
				num1=num2;
				i++;
			}
			printf("%d\n",num2);
		}
	}
	return 0;
}