#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=1e4+100;
struct node{
	int s,e;
	bool operator<(const node &a)const{//�ж�Ӧ���������
		if(s!=a.s) return s<a.s;
		else return e>a.e;
	}
}p[maxx];
int a[maxx],n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) 
		scanf("%d %d",&p[i].s,&p[i].e);
	sort(p+1,p+1+m);//����˵������Ҷ˵㽵������
	int k,i,j,st=1;
	for(k=0;k<n;k++){//�����Ĵ���=������Ҫ�ĵ���
		int _max=1;
		for(i=1;i<=n;i++){
			for(j=st;j<=m;j++) 
				if(p[j].s>a[i]||p[j].e<a[i]) 
					break;
			if(j>_max) 
				_max=j;//�������������������ٸ����䡣
		}
		st=_max;//�´ο�ʼ��ʱ�������һ�ε�ĵط���ʼ��Ѱ������ĵ�
		if(st==m+1) 
			break;//���е��߶������ˣ���ֱ���˳���
	}
	if(k==n) 
		printf("-1\n");
	else 
		printf("%d\n",k+1);
	return 0;
}