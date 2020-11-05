#include<stdio.h>
int main(){
	int i=1,count=20,num,sum=0,max;
	float avg;
	scanf("%d\n",&num);
	sum+=num;
	max=num;
	while(i<count){
		scanf("%d\n",&num);
		sum+=num;
		if(num>max)
			max=num;
		i++;
	}
	avg=(float)sum/count;
	printf("%d %.1f\n",max,avg);
	return 0;
}