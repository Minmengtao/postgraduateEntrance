#include<stdio.h>
int main(){
	int N,i;
	__int64 count;
	while(scanf("%d\n",&N)!=EOF){
		i=1;
		count=1;
		while(i<N){
			count=(count+1)*2;
			i++;
		}
		printf("%I64d\n",count);
	}

	return 0;
}