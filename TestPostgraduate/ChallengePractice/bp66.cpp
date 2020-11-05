#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode{
	int data;
	int level;
	BTNode *lchild,*rchild;
}BTNode,*BiTree;
int level,sign[102]={0};
int BST_Insert(BiTree &T,int k){
	if(T==NULL){
		T=(BiTree)malloc(sizeof(BTNode));
		T->data=k;
		T->level=level;
		int len=0;
		while(k!=0){
			k=k/10;
			len++;
		}
		if(len>sign[level])
			sign[level]=len;
		T->lchild=T->rchild=NULL;
		return 1;
	}
	else if(k>T->data){
		level++;
		BST_Insert(T->rchild,k);
	}
	else if(k<T->data){
		level++;
		BST_Insert(T->lchild,k);
	}
	else return 0;
}
void create(BiTree &T,int *num,int n){
	T=NULL;
	int i=0;
	while(i<n){
		level=1;
		BST_Insert(T,num[i]);
		i++;
	}
}
void print(BiTree T,int min,int max){
	if(T->level==1){
		printf("%d",T->data);
	}else{
		int i,j;
		for(i=1;i<T->level;i++){
			for(j=1;j<=sign[i];j++)
				printf(".");
			printf(".");
		}
		if(T->data>=min&&T->data<=max)
			printf("|-");
		printf("%d",T->data);
	}
	if(T->lchild!=NULL||T->rchild!=NULL)
		printf("-|");
	printf("\n");
}
void post(BiTree T){
	if(T!=NULL){
		int a=T->data,b=T->data;
		
		post(T->rchild);
		if(T->lchild!=NULL)
			a=T->lchild->data;
		if(T->rchild!=NULL)
			b=T->rchild->data;
		printf("%d %d\n",a,b);
		print(T,a,b);
		post(T->lchild);
	}
}
int main(){
	BiTree T=NULL;
	int s[105];
	scanf("%d",&s[0]);
	int i=1;
	while(getchar()!='\n')
		scanf("%d",&s[i++]);
	create(T,s,i);
	post(T);
	return 0;
}