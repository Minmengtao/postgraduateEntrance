#include<stdio.h>
int main(){
	char word,position='m';
	word=getchar();
	if(word>='a'&&word<='z'){
		if(word<=position)
			printf("%c\n",word+1);
		else
			printf("%c\n",word-1);
	}
	return 0;
}