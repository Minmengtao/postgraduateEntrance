#include<cstdio>
#include<cstring>
int main(){
	char name[10],pwd[10];
	int flag=1;
	scanf("%s",name);
	scanf("%s",pwd);
	while(flag){
		if(!strcmp(pwd,"123456")){
			printf("Hello %s\n",name);
			break;
		}else{
			printf("Wrong Password!\n");
			if(!strcmp(pwd,"0"))
				break;
		}
		scanf("%s",pwd);
	}
	return 0;
}