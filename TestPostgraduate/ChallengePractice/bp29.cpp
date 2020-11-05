#include<stdio.h>
void print(int P){
	if(P>=1&&P<=10)
		printf("%d",P);
	else if(P==11)
		printf("J");
	else if(P==12)
		printf("Q");
	else if(P==13)
		printf("K");
}
int main(){
	int num[55],len=0;
	char s[5];
	while(scanf("%s",s)!=EOF){
		if(s[0]>='1'&&s[0]<='9'&&s[1]=='\0')
			num[len++]=s[0]-'0';
		else if(s[0]=='1'&&s[1]=='0')
			num[len++]=10;
		else if(s[0]=='J')
			num[len++]=11;
		else if(s[0]=='Q')
			num[len++]=12;
		else if(s[0]=='K')
			num[len++]=13;
		if(len==52)
			break;
		getchar();
	}
	if(len<52)
		printf("-1\n");
	else{
		int P[55],i=0,j=0,nowCard;
		while(i<len){
			nowCard=num[j++];
			if(nowCard>i)//P中的牌数量没有num最新牌数值大
				P[i]=nowCard;
			else{
				int k=i;
				while(k>nowCard){
					P[k]=P[k-1];
					k--;
				}
				P[nowCard]=nowCard;
			}
			i++;
		}
		for(i=0;i<len;i++){
			print(P[i]);
			printf(" ");
		}
		//print(P[i]);
		//printf("\n");
	}
	return 0;
}