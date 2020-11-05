#include<stdio.h>
#include<string.h>
#include<ctype.h>
int isHw(char *str,int i,int j);
int main(){
	char s[20001],str[2001];
	int k=0;
	for(k=0;k<20001;k++){
	    s[k]=getchar();
	}
	//if(gets(s)&&strcmp(s,"")!=0)
	    //getchar();
	int i,len=strlen(s),j=0;
	for(i=0;i<len;i++)
		if((s[i]>='a'&&s[i]<='z')||(s[i]<='Z'&&s[i]>='A'))
			str[j++]=s[i];
	int len1=j,max=0,i_sign,j_sign;
	for(i=0;i<len1;i++)
		for(j=i;j<len1;j++)
			if(isHw(str,i,j)==1&&j-i+1>max){
				i_sign=i+1;
				j_sign=j+1;
				max=j-i+1;
			}
	printf("%d\n",max);
	int count=0;
	for(i=0;i<len;i++){
		char sign=tolower(s[i]);
		if(sign>='a'&&sign<='z')
			count++;
		if(count>=i_sign&&count<=j_sign)
			printf("%c",s[i]);
		if(count==j_sign)
			break;
	}
	printf("\n");
	return 0;
}
int isHw(char *str,int i,int j){
	while(j>=i){
		if(tolower(str[j])!=tolower(str[i]))
			return 0;
		j--;i++;
	}
	return 1;
}