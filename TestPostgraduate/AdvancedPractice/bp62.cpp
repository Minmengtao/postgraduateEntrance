#include<stdio.h>
#include<stdlib.h>
typedef struct S{
	char *num;
}S;
int judge1(S *s,S *s1,int n);
int judge2(S *s,S *s1,int n);
int judge3(S *s,S *s1,int n);
int judge4(S *s,S *s1,int n);
int judge5(S *s,S *s1,int n);
int judge6(S *s,S *s1,int n);
int main(){
	int i,j,n;
	S *s,*s1;
	scanf("%d",&n);
	s=(S*)malloc(sizeof(S)*n);
	s1=(S*)malloc(sizeof(S)*n);
	for(i=0;i<n;i++){
		s[i].num=(char*)malloc(sizeof(char)*n);
		s1[i].num=(char*)malloc(sizeof(char)*n);
	}
	for(i=0;i<n;i++)
		scanf("%s",s[i].num);
	for(i=0;i<n;i++)
		scanf("%s",s1[i].num);
	if(judge1(s,s1,n)==1)
		//转90度：图案按顺时针转90度。
		printf("1\n");
	else if(judge2(s,s1,n)==1)
		//转180度：图案按顺时针转180度。
		printf("2\n");
	else if(judge3(s,s1,n)==1)
		//转270度：图案按顺时针转270度。
		printf("3\n");
	else if(judge4(s,s1,n)==1)
		//反射：图案在水平方向翻转（形成原图案的镜像）。
		printf("4\n");
	else if(judge5(s,s1,n)==1)
		//组合：图案在水平方向翻转，然后按照#1-#3之一转换。
		printf("5\n");
	else if(judge6(s,s1,n)==1)
		//不改变：原图案不改变。
		printf("6\n");
	else
		//无效转换：无法用以上方法得到新图案。
		printf("7\n");
	return 0;
}
int judge1(S *s,S *s1,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(s1[j].num[n-i-1]!=s[i].num[j])
				return 0;
	return 1;
}
int judge2(S *s,S *s1,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(s1[n-i-1].num[n-j-1]!=s[i].num[j])
				return 0;
	return 1;
}
int judge3(S *s,S *s1,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(s1[n-j-1].num[i]!=s[i].num[j])
				return 0;
	return 1;
}
int judge4(S *s,S *s1,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(s[i].num[j]!=s1[i].num[n-j-1])
				return 0;
	return 1;
}
int judge5(S *s,S *s1,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n/2;j++){
			char temp=s[i].num[j];
			s[i].num[j]=s[i].num[n-j-1];
			s[i].num[n-j-1]=temp;
		}
	if(judge1(s,s1,n)==0&&judge2(s,s1,n)==0&&judge3(s,s1,n)==0)
		return 0;
	return 1;
}
int judge6(S *s,S *s1,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(s[i].num[j]!=s1[i].num[j])
				return 0;
	return 1;
}