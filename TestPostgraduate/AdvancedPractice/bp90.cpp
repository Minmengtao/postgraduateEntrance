#include<stdio.h>
#include<stdlib.h>
int id(int num);
int main(){
	int num;
	scanf("%d",&num);
	int count=0;
	num++;
	while(count<=0){
		if(id(num))
			count++;
		else{
			num++;
		}
	}
	printf("%d\n",num);
	return 0;
}
int id(int num){
	int n[10],i=0,j,k,*sign;
	while(num!=0){
		n[i]=num%10;
		if(n[i]==0)
			return 0;
		num=(num-n[i])/10;
		i++;
	}
	for(j=0;j<i-1;j++)
		for(k=j+1;k<i;k++)
			if(n[j]==n[k])
				return 0;
	for(j=0;j<=(1+i)/2-1;j++){
		int temp=n[j];
		n[j]=n[i-1-j];
		n[i-1-j]=temp;
	}
	
	sign=(int*)malloc(sizeof(int)*i);
	for(j=0;j<i;j++)
		sign[j]=0;
	j=0;
	int s=n[0],flag=0;
	while(s!=n[0]||flag==0){
		j=(j+s)%i;
		s=n[j];
		sign[j]++;
		if(sign[j]>1)
			return 0;
		flag=1;
	}
	for(j=0;j<i;j++)
		if(sign[j]!=1)
			return 0;
			
	return 1;
}