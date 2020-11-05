#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<algorithm>
using namespace std;

int main(){
	char s1[85],s2[85];
	scanf("%s %s",s1,s2);
	for(int i=0;i<strlen(s1);i++)
		s1[i]=tolower(s1[i]);
	for(int j=0;j<strlen(s2);j++)
		s2[j]=tolower(s2[j]);
	sort(s1,s1+strlen(s1));
	sort(s2,s2+strlen(s2));
	if(!strcmp(s1,s2))
		printf("Y\n");
	else
		printf("N\n");
	return 0;
}