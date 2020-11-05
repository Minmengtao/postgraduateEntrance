#include<stdio.h>
int main(){
	int N,divide;
	while(scanf("%d\n",&N)!=EOF){
		divide=0;
		if(N>=1&&N<=20000){
			while(true){
				if(N==0)
					break;
				divide+=N%10;
				N=N/10;
			}
			printf("%d\n",divide);
		}
	}
	return 0;
}