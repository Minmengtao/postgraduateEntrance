#include<stdio.h>
int common(int num1,int num2){
	int i=1,max=1;
	while(i<=num1&&i<=num2){
		if(num1%i==0&&num2%i==0&&i>max)
			max=i;
		i++;
	}
	return num1*num2/max;
}
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",common(common(a,b),c));
	return 0;
}