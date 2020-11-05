#include<stdio.h>
#include<math.h>
int composite(int num);
int f[100];
int main(){
	int n,i,j,k,m=0;
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++){
				int x1=k,x2=j*10+k,x3=i*100+x2;
				if(composite(x1)&&composite(x2)&&composite(x3))
					f[m++]=x3;
			}
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",f[n-1]);
	}
	return 0;
}
int composite(int num){
	int i;
	if(num==0)
		return 1;
	else if(num==1||num==2)
		return 0;
	else{
		for(i=2;i<num;i++)
			if(num%i==0)
				return 1;
		return 0;
	}
}