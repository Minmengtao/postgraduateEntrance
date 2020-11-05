#include<cstdio>
#include<cstring>
int main(){
	char str[1000];
	while(~scanf("%s",str)){
		int flag=0;
		for(int i=0;i<strlen(str);i++)
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'
				||str[i]=='o'||str[i]=='u'){
				flag=i+1;
				break;
			}
		printf("%d\n",flag);
	}
	return 0;
}