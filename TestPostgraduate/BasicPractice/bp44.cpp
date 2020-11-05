#include<stdio.h>
int main(){
	int count=0;
	float n,num[40],sum=0,avg;
	scanf("%f\n",&n);
	while(n>=0){
		num[count]=n;
		sum+=n;
		count++;
		if(count==40)
			break;
		scanf("%f\n",&n);
	}
	avg=(float)sum/count;
	int i=0,a_count=0;
	for(;i<count;i++)
		if(num[i]>=avg)
			a_count++;
	printf("%d\n",a_count);
	return 0;
}