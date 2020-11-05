#include<stdio.h>
#include<string.h>
int order(char *s);
int main(){
	char s1[27],s2[27],s3[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
		,'q','r','s','t','u','v','w','x','y','z'};
	while(scanf("%s\n%s",s1,s2)!=EOF){
		int len1=order(s1),len2=order(s2);//处理完后无重复字符
		int sign[26],i,j=0,k=0;
		for(i=0;i<26;i++){
			sign[i]=0;
			if(s3[i]==s1[j]){
				sign[i]++;
				j++;
			}
			if(s3[i]==s2[k]){
				sign[i]++;
				k++;
			}
		}
		printf("in s1 or s2:"); 
		for(i=0;i<26;i++)
			if(sign[i]>0)
				printf("%c",s3[i]);
		printf("\nin s1 and s2:");
		for(i=0;i<26;i++)
			if(sign[i]==2)
				printf("%c",s3[i]);
		printf("\nin s1 but not in s2 ,or in s2 but not in s1:");
		for(i=0;i<26;i++)
			if(sign[i]==1)
				printf("%c",s3[i]);
		printf("\nnot in s1 and s2:");
		for(i=0;i<26;i++)
			if(sign[i]==0)
				printf("%c",s3[i]);
		printf("\n\n");
	}
	return 0;
}
int order(char *s){
	int len=strlen(s);
	int i,j;
	for(i=0;i<len;i++)
		for(j=i;j<len;j++)
			if(s[i]>s[j]){
				char temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	j=0;
	for(i=1;i<len;i++){
		if(s[j]!=s[i]){
			j++;
			s[j]=s[i];
		}
	}
	j++;
	return j;
}