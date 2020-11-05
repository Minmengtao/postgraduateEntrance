#include<cstdio>
int num1,num2;
int main(){
	while(~scanf("%d %d",&num1,&num2)){
		int sign=0,count=0;
		while(num1!=0||num2!=0){
			int x1=num1%10,x2=num2%10;
			if(x1+x2+sign<10)
				sign=0;
			else{
				count++;
				sign=(x1+x2+sign)/10;
			}
			num1/=10;num2/=10;
		}
		if(count==0)
			printf("No carry operation.\n");
		else
			printf("%d carry operation.\n",count);
	}
	return 0;
}