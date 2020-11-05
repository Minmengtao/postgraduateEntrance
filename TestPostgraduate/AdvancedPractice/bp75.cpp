#include<stdio.h>
#include<string.h>
int main(){
	char s[11];
	while(~scanf("%s",s)){
		int count=0,i=0,j,k,len=strlen(s);
		if(s[0]=='@'&&len==1){
			printf("@");
			continue;
		}
		if(s[0]<'0'||s[0]>'9'){
			count++;
			printf("%c",s[i]);
			i++;
		}
		while(s[i]!='@'&&i<len-1){
			if(s[i]<='9'&&s[i]>='0'){
				for(j=1;j<=(int)(s[i]-'0')+1;j++){
					if(count%3==0&&count!=0)
						printf(" ");
					printf("%c",s[i+1]);
					count++;
					
				}
				if(s[i+1]=='@')
					break;
			}else{
				if(count%3==0&&count!=0)
					printf(" ");
				printf("%c",s[i]);
				count++;
				if(count%3==0&&count!=0)
					printf(" ");
				printf("%c",s[i+1]);
				count++;
				
			}
			i+=2;
		}
		if(s[i]=='@'&&i!=0){
			if(count%3==0&&count!=0)
				printf(" ");
			printf("@");
			count++;
			
		}
		printf("\n");
	}
	return 0;
}