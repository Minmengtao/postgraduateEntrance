#include<stdio.h>
#include<string.h>
int isHw(char[],int); 
int main(){
	char str[200];
	while(scanf("%s\n",str)!=EOF){
		int len=strlen(str);
		if(isHw(str,len)==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
int isHw(char str[],int len){
	int i=0;
	while(i<=(len-1)/2){
		if(str[i]!=str[len-1-i])
			return 0;
		i++;
	}
	return 1;
}