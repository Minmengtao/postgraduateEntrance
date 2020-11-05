#include<stdio.h>
#include<string.h>
int main(){
	int m;
	scanf("%d\n",&m);
	while(m--){
		char s[1000];
		int count=0,i;
		scanf("%s",s);
		int len=strlen(s);
		for(i=0;i<len;i++)
			if(s[i]>='a'&&s[i]<='z')
				count++;
		printf("%d\n",count);
	}
	return 0;
}