#include<cstdio>
int sig[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char si[11]={'1','0','x','9','8','7','6','5','4','3','2'};
int main(){
	char pre[15],order[18];
	scanf("%s",pre);
	int i=0,j=0,sum=0;
	while(i<15&&j<17){
		if(j==6){
			order[6]='1';
			order[7]='9';
			j=8;
			sum+=(order[6]-'0')*sig[6]+(order[7]-'0')*sig[7];
			continue;
		}
		order[j++]=pre[i++];
		sum+=(order[j-1]-'0')*sig[j-1];
	}
	sum%=11;
	order[17]=si[sum];
	for(i=0;i<18;i++)
		printf("%c",order[i]);
	printf("\n");
	return 0;
}