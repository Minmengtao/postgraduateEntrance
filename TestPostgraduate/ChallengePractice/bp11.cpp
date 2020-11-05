#include<stdio.h>
#include<string.h>
#include<ctype.h>
int judge(char *str1,char *str2,int len);
int main(){
	char str1[11],str2[11];
	scanf("%s",str1);
	scanf("%s",str2);
	int len1=strlen(str1),len2=strlen(str2);
	if(len1!=len2)
		printf("1\n");
	else{
		switch(judge(str1,str2,len1)){
			case 0:printf("2\n");break;
			case 1:printf("3\n");break;
			case 2:printf("4\n");break;
		}
	}
	return 0;
}
int judge(char *str1,char *str2,int len){
	int i;
	for(i=0;i<len;i++)
		if(str1[i]!=str2[i]&&tolower(str1[i])!=tolower(str2[i]))
			return 2;
	for(i=0;i<len;i++){
		if(str1[i]!=str2[i]&&tolower(str1[i])==tolower(str2[i]))
			return 1;
		else
			continue;
	}
	return 0;
}