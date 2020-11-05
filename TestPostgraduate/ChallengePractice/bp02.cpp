#include<stdio.h>
int isHw(int n);
int main(){
	int n,i;
	scanf("%d",&n);
	if(n<=1000){
		for(i=1001;i<10000;i++)
			if(isHw(i))
				printf("%d\n",i);
	}
	else{
		for(i=n;i<10000;i++)
			if(isHw(i))
				printf("%d\n",i);
	}
	return 0;
}
int isHw(int n){
	int num[4],i=0;
	while(n!=0&&i<4){
		num[i]=n%10;
		n=(n-num[i])/10;
		i++;
	}
	if(num[0]==num[3]&&num[1]==num[2])
		return 1;
	else
		return 0;
}