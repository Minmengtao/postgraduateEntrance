#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct S{
	char str[100];
}S;
int order(S *s,int n);
int isTrue(S s1,S s2,int n1,int len1,int len2,int sign);
int main(){
	int n;
	S *s;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		s=(S*)malloc(sizeof(S)*n);
		int i;
		for(i=0;i<n;i++)
			scanf("%s",s[i].str);
		order(s,n);
		for(i=0;i<n;i++)
			printf("%s",s[i].str);
		printf("\n");
		free(s);
	}
	return 0;
}
int order(S *s,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			int len1=strlen(s[i].str);
			int len2=strlen(s[j].str);
			int r=0,flag=0;
			while(r<len1&&r<len2){
				if(s[i].str[r]==s[j].str[r]){
					r++;
					continue;
				}
				else if(s[i].str[r]<s[j].str[r]){
					flag=1;
					r++;
					break;
				}
				else{
				    flag=-1;
					break;
				}
			}
			//if(flag==0&&((len2<len1&&s[i].str[r]<s[j].str[0])||
			//	(len1<len2&&s[i].str[0]<s[j].str[r]))){
			if(flag==0&&((len2<len1&&isTrue(s[j],s[i],r,len2,len1,1)==1)||
				(len1<len2&&isTrue(s[i],s[j],r,len1,len2,2)==1))){
				flag=1;
			}
			S temp;
			if(flag==1){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	return 1;
}
int isTrue(S s1,S s2,int n1,int len1,int len2,int sign){//len1<len2，n1为s2的初始起点
	int i=0;
	while(n1<len2){
		if(s1.str[i]==s2.str[n1]){
			i=(i+1)%len1;
			n1++;
			if(n1==len2&&((sign==2&&s1.str[len1-1]<s2.str[len2-1])||(sign==1&&s1.str[len1-1]>s2.str[len2-1])))
			    return 1;
			else
			    continue;
		}
		else if(s1.str[i]<s2.str[n1]){
			if(sign==2)
				return 1;
			else
				break;
		}
		else{
			if(sign==1)
				return 1;
			else
				break;
		}
	}
	return 0;
}