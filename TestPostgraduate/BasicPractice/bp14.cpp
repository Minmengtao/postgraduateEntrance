#include<stdio.h>
#include<stdlib.h>
char alterLetter(char);
int main(){
	int i=0,j=0;
	char *a=(char*)malloc(sizeof(char));
	char word;
	while(scanf("%c\n",&word)!=EOF){
		a[i]=word;
	    a=(char*)realloc(a,sizeof(char));
		i++;
	}
	while(j<i){
		printf("%c\n",alterLetter(a[j]));
		j++;
	}
	return 0;
}
char alterLetter(char word){
	char position='m';
	if(word<=position)
		return word+1;
	else
		return word-1;
}