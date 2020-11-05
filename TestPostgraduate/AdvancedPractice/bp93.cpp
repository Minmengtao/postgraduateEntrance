#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,i=0,j,flag,k,sign=0;
	char *str,s,*str1,*str2;
	scanf("%d",&n);
	str=(char*)malloc(sizeof(char)*n);
	str1=(char*)malloc(sizeof(char)*n);
	str2=(char*)malloc(sizeof(char)*n);
	while(i<n){
		s=getchar();
		if(s!='\n'){
			str[i]=s;
			i++;
		}
	}
	strcpy(str1,str);
	for(i=0;i<n;i++){
		j=i;flag=0;k=0;
		while(j!=i||flag==0){
			str2[k++]=str[j];
			j=(j+1)%n;
			flag=1;
		}
		if(strcmp(str1,str2)>0){
			strcpy(str1,str2);
			sign=i+1;
		}
	}
	printf("%d\n",sign-1);
	return 0;
}