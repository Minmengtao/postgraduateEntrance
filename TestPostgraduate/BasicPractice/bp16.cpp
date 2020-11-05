#include<stdio.h>
int main(){
	int i;
	float sum=0.0;
	while(scanf("%d",&i)!=EOF){
		if(i>=0&&i<=20)
			sum=i*5;
		else if(i>20&&i<=40)
			sum=i*5*0.9;
		else if(i>40&&i<=80)
			sum=i*5*0.85;
		else if(i>80&&i<=120)
			sum=i*5*0.8;
		else if(i>120&&i<=1000)
			sum=i*5*0.7;
		else
			sum=0;
		printf("%.2f\n",sum);
	}
	return 0;
}