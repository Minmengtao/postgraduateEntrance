#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int rel[105][105]={{0}};
int state[105][105]={{0}};
int num=105,n,m;
void dfs(int x,int cls){//x ����ǰ�����˶��ٸ���cls��������
	if(cls>num)
		return;
	if(x==n+1){//����Ѿ�������n���ˣ������ж�  
		num=min(num,cls);
		return;
	}
	int j,k;
	for(j=1;j<=cls;j++){//ö�ٿ���
		k=0;
		while(state[j][k]&&!rel[x][state[j][k]])//�ҵ�һ����λ ������ÿ������޹�ϵ 
			k++;
		if(state[j][k]==0){//�������� ������һ���� 
			state[j][k]=x;
			dfs(x+1,cls);
			state[j][k]=0;
		}
	}//���� 
	state[j][0]=x;
	dfs(x+1,cls+1);// ������з��䶼���������� ���ӷ��� 
	state[j][0]=0;//���� 
}
int main(){
	int x1,x2;
	scanf("%d\n%d",&n,&m);
	for(int i=1;i<=m;i++){ 
		scanf("%d%d",&x1,&x2);
		rel[x1][x2]=rel[x2][x1]=1;
	}
	dfs(1,1);
	printf("%d\n",num);
	return 0;
}