#include<stdio.h>
#include<ctype.h>
int main(){
	char up,low;
	up=getchar();
	if(up>='A'&&up<='Z'){
		low=tolower(up);
		printf("%c",low);
	}
	return 0;
}