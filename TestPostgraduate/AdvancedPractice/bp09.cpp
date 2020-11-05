#include<stdio.h>
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		int n=0,i=1;
		for(;i<=N;i++){
			int t=i;
			while(t%5==0&&t>=5){
				n++;
				t=t/5;
			}
		}
		printf("%d\n",n);
	}
	return 0;
}