#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int x;
	int y;
}Node;
int order(Node *node,int len);
int main(){
	int L,M;
	Node *node;
	while(scanf("%d %d\n",&L,&M)!=EOF){
		node=(Node*)malloc(sizeof(Node)*M);
		int i=0;
		while(i<M){
			scanf("%d %d",&node[i].x,&node[i].y);
			i++;
		}
		order(node,M);
		Node temp=node[0];
		int sum=0;
		for(i=1;i<M;i++){
			if(temp.y<node[i].x){
				sum=sum+temp.y-temp.x+1;
				temp=node[i];
			}else if(temp.y<node[i].y){
				temp.y=node[i].y;
			}
			else
				continue;
		}
		sum=sum+temp.y-temp.x+1;
		printf("%d\n",L+1-sum);
		free(node);
	}
	return 0;
}
int order(Node *node,int len){
	int i,j;
	Node temp;
	for(i=0;i<len-1;i++)
		for(j=i;j<len;j++)
			if(node[i].x>node[j].x){
				temp=node[i];
				node[i]=node[j];
				node[j]=temp;
			}
	return 1;
}