#include<cstdio>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,sum[30],weight[30],goods[20];
bool dfs(int left,int k){
	if(sum[k]<abs(left))	//ʣ�µ����붼�ŵ��Ҷ���ƽ������ƽ��
		return false;
	if(left==0||abs(left)==sum[k])	//��ƽƽ���˻���ʣ�µ����붼�����Ҷ���ƽ��
		return true;
	if(k==n)		//������n��������Ȼû�Ƴ���
		return false;
	if(dfs(left-weight[k],k+1))	//�������� 
		return true;
	if(dfs(left+weight[k],k+1))	//�������� 
		return true;	
	if(dfs(left,k+1))		//����
		return true;	
	return false;
}
int main(){
	int all=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
		all+=weight[i];	
	}
	for(int j=0;j<m;j++)
		scanf("%d",&goods[j]);
	sort(weight,weight+n,greater<int>());
	sum[0]=all;
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]-weight[i-1];//��i����Ʒ�����һ����Ʒ��������
	for(int i=0;i<m;i++){
		if(dfs(goods[i],0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}