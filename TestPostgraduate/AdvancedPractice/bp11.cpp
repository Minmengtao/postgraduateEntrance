#include<stdio.h>
int main(){
	int a,b,c;
	while(scanf("%d %d %d\n",&a,&b,&c)!=EOF){
		int x1,x2,x3,count=0,i;
		x1=a*100+b*10+c;
		x2=c*100+b*10+a;
		x3=x1*x2;
		printf("%d ",x3);
		while(x3%10!=0||x3/10!=0){
			if(x3%10!=0){
				i=x3%10;
				if(i==a||i==b||i==c)
					count++;
				x3=x3/10;
			}
			else{
				i=x3%10;
				if(i==a||i==b||i==c)
					count++;
				x3=x3/10;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}