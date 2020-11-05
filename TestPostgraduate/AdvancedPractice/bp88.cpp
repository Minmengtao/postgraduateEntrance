#include<stdio.h>
typedef struct Divide{
	int ne;//分子
	int du;//分母
	double div;//结果
}Divide;
int is(int num1,int num2);
int main(){
	int n;
	Divide di[128];
	while(scanf("%d",&n)!=EOF){
		if(n>0&&n<=20){
			int i,j;
			di[0].ne=0;
			di[0].du=1;
			di[0].div=0.0;
			int count=1;
			for(i=1;i<n;i++)
				for(j=n;j>i;j--)
					if(is(j,i)==1||i==1){
						di[count].ne=i;
						di[count].du=j;
						di[count].div=(double)i/j;
						count++;
					}
			for(i=0;i<count;i++)
				for(j=i;j<count;j++)
					if(di[i].div>di[j].div){
						Divide temp=di[i];
						di[i]=di[j];
						di[j]=temp;
					}
			for(i=0;i<count;i++)
				printf("%d/%d\n",di[i].ne,di[i].du);
		}
	}		
	return 0;
}
int is(int num1,int num2){
	int i;
	for(i=2;i<=num2;i++)
		if(num1%i==0&&num2%i==0)
			return 0;
	return 1;
}