#include<cstdio>
int main(){
	__int64 num;
	scanf("%I64d",&num);
	while(num>10){
		__int64 x=1;
		while(num!=0){
			int a=num%10;
			if(a)
				x*=a;
			num/=10;
		}
		num=x;
	}
	printf("%I64d\n",num);
	return 0;
}