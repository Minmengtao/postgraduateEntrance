#include<stdio.h>
typedef struct Ant{
	double x;
	int dir;
	int in;
}Ant;
int n;
Ant ant[50];
void order(){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if(ant[i].x>ant[j].x){
				Ant t=ant[i];
				ant[i]=ant[j];
				ant[j]=t;
			}
}
int judge(){
	int i;
	for(i=0;i<n;i++)
		if(ant[i].x>0&&ant[i].x<100)
			return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	int i,x,flag=1;
	double t=0.5;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x>0){
			ant[i].x=x;
			ant[i].dir=1;
		}else{
			ant[i].x=x*(-1);
			ant[i].dir=-1;
		}
		if(i==0)
			ant[i].in=0;
		else
			ant[i].in=1;
	}
	order();
	while(flag==1){
		if(judge())
			break;
		for(i=0;i<n;i++)
			if(ant[i].x>0&&ant[i].x<100)
				ant[i].x+=t*ant[i].dir;
		for(i=0;i<n;i++){
			if(ant[i].x>0&&ant[i].x<100){
				if(ant[i].x==ant[i-1].x&&ant[i-1].x>0&&i-1>=0){//处理左边情况
					x=ant[i].in&ant[i-1].in;
					ant[i].in=x;
					ant[i-1].in=x;
					ant[i].dir=1;
					ant[i-1].dir=-1;
				}
				if(ant[i].x==ant[i+1].x&&ant[i+1].x<100&&i+1<n){//处理右边情况
					x=ant[i].in&ant[i+1].in;
					ant[i].in=x;
					ant[i+1].in=x;
					ant[i].dir=-1;
					ant[i+1].dir=1;
				}
				
			}
		}
	}
	int count=0;
	for(i=0;i<n;i++)
		if(ant[i].in==0)
			count++;
	printf("%d\n",count);
	return 0;
}