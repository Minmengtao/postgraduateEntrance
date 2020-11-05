#include<stdio.h>
int main(){
	int i,count;
	scanf("%d",&i);
	if(i<1||i>9999)
		printf("error!");
	else{
		while(i!=0){
			count=i%10;
			printf("%d",count);
			i=i/10;
		}
		printf("\n");
	}
	return 0;
}