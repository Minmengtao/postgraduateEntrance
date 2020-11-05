#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char s[1000];
		int M;
		getchar();
		scanf("%[^\n]",s);
		//gets(s);
		scanf("%d",&M);
		int i=0;
		while(s[i]!='\0'){
			if(s[i]==' '){
				if(s[i+1]=='\0')
				    printf("0");
				else 
				    printf("0 ");
			}
			else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
			    int k=toupper(s[i])-'A'+1+M;
			    if(s[i+1]=='\0')
				    printf("%d",k);
				else 
				    printf("%d ",k);
			}
			else{
			    int k=s[i]+100;
			    if(s[i+1]=='\0')
				    printf("%d",k);
				else 
				    printf("%d ",k);
			}
			i++;
		}
		printf("\n");
	}
	return 0;
}