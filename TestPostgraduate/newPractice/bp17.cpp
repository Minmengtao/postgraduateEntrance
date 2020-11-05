#include<cstdio>
#include<cmath>
int judge(int x){//判断数x是否为质数
	if(x==2||x==3)
		return 1;
	else{
		for(int i=2;i<=sqrt(x);i++)
			if(x%i==0)
				return 0;
		return 1;
	}
}
int main(){
	int num,a[1000],j=0;
	scanf("%d",&num);
	printf("%d=",num);
	for(int i=2;i<=num;i++){
		if(num==1)
			break;
		if(judge(i))
			while(num%i==0){
				a[j++]=i;
				num/=i;
			}
	}
	int k=0;
	while(k<j-1)
		printf("%d*",a[k++]);
	printf("%d\n",a[k]);
	return 0;
}