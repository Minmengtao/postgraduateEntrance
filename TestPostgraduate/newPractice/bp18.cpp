#include<cstdio>
int date[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int judge(int y){//ÅĞ¶ÏyÊÇ·ñÊÇÈòÄê
	if((y%4==0&&y%100!=0)||(y%400==0))
		return 1;
	else
		return 0;
}
int main(){
	int n,sum=4,cnt=0;
	scanf("%d",&n);
	for(int x=1998;x<n;x++){
		if(judge(x))
			sum+=366;
		else
			sum+=365;
	}
	if(judge(n))
		date[1]++;
	for(int i=0;i<12;i++){
		sum+=12;
		if(i>0)
			sum+=date[i-1];
		if(sum%7==5)
			cnt++;
		sum-=12;
	}
	printf("%d\n",cnt);
	return 0;
}