#include<stdio.h>
#include<stdlib.h>
int reverse(int *num,int len,int *num1);
int isNum(int *div,int len);
int main(){
	int num;
	while(scanf("%d",&num)!=EOF){
		if(num==0)
			break;
		int div[50000],i=0,len=0,flag=0,*num1;
		while(num!=0){
			div[len]=num%10;
			num=(num-div[len])/10;
			len++;
		}
		while(!isNum(div,len)||!flag){//是否为回文
			num1=(int*)malloc(sizeof(int)*len);
			reverse(div,len,num1);//逆序数
			for(i=len-1;i>=0;i--)
				printf("%d",div[i]);
			printf("+");
			int count=0;
			for(i=len-1;i>=0;i--){
				if(num1[i]==0&&count==0)
					continue;
				else{
					printf("%d",num1[i]);
					count=1;
				}
			}
			printf("=");
			int sign=0,pre_div;
			i=0;
			while(i<len){
				if(div[i]+num1[i]+sign<=9){
					div[i]=div[i]+num1[i]+sign;
					sign=0;
				}
				else{
					pre_div=div[i];
					div[i]=(div[i]+num1[i]+sign)%10;
					sign=(pre_div+num1[i]+sign-div[i])/10;
				}
				i++;
			}
			while(sign!=0){
				if(sign<=9){
					div[len]=sign;
					sign=0;
				}else{
					div[len]=sign%10;
					sign=(sign-div[len])/10;
				}
				len++;
			}
			flag=1;
			for(i=len-1;i>=0;i--)
				printf("%d",div[i]);
			printf("\n");
		}
	}
	return 0;
}
int reverse(int *num,int len,int *num1){
	int i;
	for(i=0;i<len;i++)
		num1[i]=num[len-1-i];
	return 1;
}
int isNum(int *div,int len){
	int j;
	for(j=0;j<=(len+1)/2-1;j++)
		if(div[j]!=div[len-1-j])
			return 0;
	return 1;
}