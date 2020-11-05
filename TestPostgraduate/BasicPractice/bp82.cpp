#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct String{
	char str;
	int count;
}String;
int swap(String s[],int);
int contain(String s[],char a,int);
int main(){
	char string[100]="";
	while(scanf("%[^\n]\n",string)!=EOF){
		int i,len=strlen(string);
		//printf("%d %s",len,string);
		String s[100];
		int k=0;
		for(i=0;i<len;i++)
			if((string[i]>='a'&&string[i]<='z')||(string[i]>='A'&&string[i]<='Z')){
				char mcm=toupper(string[i]);
				if(k==0||contain(s,mcm,k)==1){
					s[k].str=mcm;
					s[k].count=1;
					k++;
				}
				else{
					int j;
					for(j=0;j<k;j++)
						if(s[j].str==mcm){
							s[j].count++;
							break;
						}
				}
			}
		swap(s,k);
		for(i=0;i<k;i++)
			printf("%c %d\n",s[i].str,s[i].count);
		printf("\n");
	}
	return 0;
}
int contain(String s[],char a,int len){
	if(len==0)
		return 0;
	int i=0;
	while(i<len){
		if(s[i].str==a)
			return 0;
		i++;
	}
	return 1;
}
int swap(String s[],int len){
	int i,j;
	String temp;
	for(i=0;i<len-1;i++)
		for(j=i+1;j<len;j++)
			if((s[i].count<s[j].count)||(s[i].count==s[j].count&&s[i].str>s[j].str)){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	return 1;
}