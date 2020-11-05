#include<stdio.h>
#include<string.h>
int main(){
	char str[1000];
	while(gets(str)&&strcmp(str,"")!=0){
		int sum=0,i,len=strlen(str);
		int x1=0,flag=0;
		char sign='+';
		for(i=0;i<len;i++){
			if(str[i]==' ')
				continue;
			else if(str[i]=='-'||str[i]=='+'){
				if(sign=='+')
					sum+=x1;
				if(sign=='-')
					sum-=x1;
				sign=str[i];
				flag=0;
			}
			else{
				if(flag)
					x1=x1*10+str[i]-'0';
				else
					x1=str[i]-'0';
				flag=1;
			}
		}
		if(sign=='+')
			sum+=x1;
		if(sign=='-')
			sum-=x1;
		printf("%d\n",sum);
	}
	return 0;
}