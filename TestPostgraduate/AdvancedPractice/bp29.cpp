#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int num[9],i=0,count=0;
		while(i<9){
			scanf("%d",&num[i]);
			i++;
		}
		for(i=0;i<9;i++){
			int sum1=0,j=i,flag=0;
			double sum2=0,sum;
			while(j!=i||flag==0){
				sum1=sum1*10+num[j];
				flag=1;
				sum2=sum2*0.1+num[j];
				j=(j+1)%9;
			}
			sum2=sum2*100000000;
			sum=sum2>sum1?sum2-sum1:sum1-sum2;
			if((int)sum%396==0)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}