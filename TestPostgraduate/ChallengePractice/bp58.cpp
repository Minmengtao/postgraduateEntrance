/*#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	long data;
	struct Node *next;
}Node;
long m,n,count;
long a[1000005]={0};
Node *L;
void init(){//��������ŵ�����
	long i=1;
	L=(Node*)malloc(sizeof(Node));
	Node *s,*r;
	r=L;
	while(i<=n){
		s=(Node*)malloc(sizeof(Node));
		s->data=i;
		r->next=s;
		r=s;
		i++;
	}
	r->next=NULL;
}
long print(){//������(m,n)�����ڵ��������ж��ٸ�
	Node *x=L->next;
	long count=0;
	while(x!=NULL){
		if(x->data>m&&x->data<n)
			count++;
		x=x->next;
	}
	return count;
}
void Delete(){//���չ���ɾ����
	Node *x=L->next;
	long i=x->next->data,len=1,j=1;
	count=0;
	while(i<=n-count){//���������ֵ�����������˳�ѭ��
		Node *pre;
		//long j=1;
		while(x!=NULL){
			j++;
			pre=x;
			x=pre->next;
			if(x==NULL)
				break;
			if(j%i==0){//���jΪi�ı���ʱɾȥ
				Node *q=x;
				pre->next=q->next;
				free(q);
				count++;
				j++;
				x=pre->next;
			}
		}
		len++;//�ۼ��Ѿ��ж��ٸ�������
		x=L->next;
		long k=1;
		Node *p=x;
		while(k<len){//ѭ�������һ������������ֵ
			p=p->next;
			k++;
		}
		x=p;
		j=len;
		i=p->data;
	}
}
int main(){
	L=NULL;
	scanf("%ld %ld",&m,&n);
	init();
	Delete();
	printf("%ld",print());
	printf("\n");
	return 0;
}*/
#include<cstdio>
long int a[500005],m,n;
void luckyNumber(int start,int len){
	int k=start,num=a[start],i;
	for(i=k;i<len;i++)	
		if(i%num!=0) 
			a[k++]=a[i];
	if(num<len)
		luckyNumber(start+1,k);
}
int main(){
	int i,len=500000,kinds=0;
	scanf("%ld %ld",&m,&n);
	for(i=1;i<len;i++){
		if(2*i-1<=n)
			a[i]=2*i-1;
		else
			break;
	}
	luckyNumber(2,i+1);//len);
	for(i=1;i<len;i++){
		if(a[i]>=n||a[i]==a[i-1]) 
			break;
		if(a[i]>m && a[i]<n)  
			kinds++;
	}
	printf("%d\n",kinds);
	return 0;
}