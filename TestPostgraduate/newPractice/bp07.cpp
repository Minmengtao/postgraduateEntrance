#include<cstdio>
int main(){
	__int64 m;
	while(~scanf("%I64d",&m)){
		int sum1=0,sum2=0;
		while(m%4==0){
			sum1++;
			m/=4;
		}
		while(m%7==0){
			sum2++;
			m/=7;
		}
		printf("%d %d\n",sum1,sum2);
	}
	return 0;
}