#include<cstdio>
int y,m;
int judge(){//ÅĞ¶ÏyÊÇ·ñÊÇÈòÄê
	if((y%4==0&&y%100!=0)||(y%400==0))
		return 1;
	else
		return 0;
}
int main(){
	int date[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(~scanf("%d%d",&m,&y)){
		if(judge()&&m==2)
			printf("29\n");
		else
			printf("%d\n",date[m-1]);
	}
	return 0;
}