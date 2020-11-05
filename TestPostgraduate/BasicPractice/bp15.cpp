#include<stdio.h>
int main(){
	int i;
	while(scanf("%d",&i)!=EOF){
		if(i==2||i==3)
			printf("One.");
		else if(i==4)
			printf("Two.");
		else if(i==5||i==6)
			printf("Three.");
		else
			printf("No.");
	}
	return 0;
}