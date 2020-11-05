#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
void add(char *a,char *b,char *c){
	int sign=0,x,aa,bb;
	for(int j=0;j<10001;j++){
		if(a[j]=='\0'&&b[j]=='\0')
			break;
		if(a[j]!='\0')
			aa=a[j]-'0';
		else
			aa=0;
		if(b[j]!='\0')
			bb=b[j]-'0';
		else
			bb=0;
		x=aa+bb+sign;
		if(x<10){
			c[j]=x+'0';
			sign=0;
		}
		else{
			sign=x/10;
			c[j]=x%10+'0';
		}
	}
	if(sign!=0)
		c[j]=sign+'0';
}
int main(){
	char a[10001]={'\0'},b[10001]={'\0'},c[10001]={'\0'},sum[100001]={'\0'},fm[10001]={'\0'};
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	a[0]='1';b[0]='1';
	sum[0]='2';
	int j;
	for(int i=3;i<=m||i<=n;i++){
		add(a,b,c);
		if(i<=n)
			add(c,sum,sum);
		if(i==m)
			strcpy(fm,c);
		strcpy(a,b);
		strcpy(b,c);
	}
	printf("\n");
	return 0;
}