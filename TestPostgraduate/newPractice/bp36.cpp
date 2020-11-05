#include<cstdio>
#include<cstring>
int toDecimal(char x){
	if(x>='0'&&x<='9')
		return x-'0';
	else
		return x-'A'+10;
}
int main(){
	int bin;
	char str[1000];
	while(~scanf("%d %s",&bin,str)){
		int sum=0;
		for(int i=0;i<strlen(str);i++)
			sum=sum*bin+toDecimal(str[i]);
		printf("%d\n",sum);
	}
	return 0;
}