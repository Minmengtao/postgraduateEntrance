#include<stdio.h>
#include<stdlib.h>

int len(int *num,int N);
int push(int *num,int N,int *front,int *rear);
int pop(int *num,int N,int *front,int *rear);
int main(){
	int N,X;
	int *num;
	while(scanf("%d %d",&N,&X)!=EOF){
		num=(int*)malloc(sizeof(int)*(N+1));
		int i,count=1;
		for(i=0;i<=N;i++)
			num[i]=i;
		int front=1,rear=0;
		//printf("a");
		while(len(num,N)!=1){
			//printf("b");
			if(count%X==0){
				int x=pop(num,N,&front,&rear);
			//	printf("c");
				printf("%d ",x);
			}
			else{
				push(num,N,&front,&rear);
			//	printf("d");
			}
			count++;
		}
		//printf("e");
		int x=pop(num,N,&front,&rear);
		printf("%d\n",x);
	}
	return 0;
}
int len(int *num,int N){
	int i,count=0;
	for(i=0;i<=N;i++)
		if(num[i]!=0)
			count++;
	return count;
}
int push(int *num,int N,int *front,int *rear){
	int x=num[*front];
	num[*front]=0;
	num[*rear]=x;
	*front=(*front+1)%(N+1);
	*rear=(*rear+1)%(N+1);
	return 0;
}
int pop(int *num,int N,int *front,int *rear){
	int x=num[*front];
	num[*front]=0;
	*front=(*front+1)%(N+1);
	return x;
}