#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int temp,temp1=1,temp2=0,temp3=0,temp4=0,temp5=0,temp6=0,i=2;
		while(i<=n){
			temp6=temp5;
			temp5=temp4;
			temp4=temp3;
			temp3=temp2;
			temp2=temp1;
			temp1=temp5+temp4+temp3;
			i++;
		}
		temp=temp1+temp2+temp3+temp4+temp5+temp6;
		printf("%d\n",temp);
	}
	return 0;
}