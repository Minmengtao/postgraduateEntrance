#include<stdio.h>
#include<stdlib.h>
typedef struct Character{
	char *c;
}Char;
int main(){
	Char *ch;
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	ch=(Char *)malloc(sizeof(Char)*n);
	for(i=0;i<n;i++)
		ch[i].c=(char*)malloc(sizeof(char)*m);
	for(i=0;i<n;i++){
		ch[i].c[i]='A';
		for(j=i-1;j>=0;j--)
			ch[i].c[j]=ch[i].c[j+1]+1;
		for(j=i+1;j<m;j++)
			ch[i].c[j]=ch[i].c[j-1]+1;
		for(j=0;j<m;j++)
			printf("%c",ch[i].c[j]);
		printf("\n");
	}
	return 0;
}