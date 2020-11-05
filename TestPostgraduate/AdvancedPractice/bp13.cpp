#include<stdio.h>
#include<math.h>
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		if(N<1||N>9)
			break;
		__int64 i=1;
		int flag=0;
		if(N==1)
			printf("7\n");
		else{
		while(i<=99999){
			__int64 j=i;
			int count=1;
			while(j/10!=0){
				count++;
				j=j/10;
			}
			__int64 x1=i*10+7,x2=i+7*pow(10,count);
			if(x2==x1*N){
				printf("%d\n",x1);
				flag=1;
			}
			i++;
		}
		if(flag==0)
			printf("No\n");
		}
	}
	return 0;
}