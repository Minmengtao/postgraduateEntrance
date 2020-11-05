#include<stdio.h>
int transfer(int S,int n);
int main(){
	int N,S;
	scanf("%d %d",&N,&S);
	int i=0,j=2;
	while(i<N){
		S++;
		int count=0;
		for(j=2;j<=10;j++){
			if(transfer(S,j)==1)
				count++;
			if(count>=2){
				printf("%d\n",S);
				i++;
				break;
			}
		}
	}
	return 0;
}
int transfer(int S,int n){//转换进制，并判断是否回文
	int num[14],i=0,temp=S;
	while(temp!=0&&i<=14){
		num[i]=temp%n;
		i++;
		temp=temp/n;
	}
	int j=0;
	for(j=0;j<=(i-1)/2;j++)
		if(num[j]!=num[i-1-j])
			return 0;
	return 1;
}