#include<stdio.h>
int main(){
	float num1,num2,result=0.0;
	int operate;
	scanf("%f %f %d",&num1,&num2,&operate);
	if(num2==0&&operate==4){
		printf("error!\n");
	}
	else{
		switch(operate){
			case 1: result=num1+num2;break;
			case 2: result=num1-num2;break;
			case 3: result=num1*num2;break;
			case 4: result=num1/num2;break;
		}
		printf("%.2f\n",result);
	}
	return 0;
}
