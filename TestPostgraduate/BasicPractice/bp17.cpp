#include<stdio.h>
#include<math.h>
int main(){
	int i,count;
	while(scanf("%d\n",&i)!=EOF){
		if(i>=1&&i<=8848){
			count=floor(log(i*100)/log(2))+1;
			printf("%d\n",count);
		}
	}
	return 0;
}