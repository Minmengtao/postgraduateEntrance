#include<stdio.h>
int main(){
	double a,b,c,signal=0;
	char sign;
	scanf("%lf %lf\n",&a,&b);
	scanf("%c\n",&sign);
	switch(sign){
		case '+':c=a+b;break;
		case '-':c=a-b;break;
		case '*':c=a*b;break;
		case '/':
			if(b==0)
				signal=1;
			else
				c=a/b;
			break;
	}
	if(signal==1)
		printf("Wrong!\n");
	else
		printf("%.1f\n",c);
	return 0;
}