#include<stdio.h>
int n,m[10][10],count=0;
int check(int x,int y){//�жϵ�x�У���y���ܲ��ܷ�����
	int i,index;
	if(m[x][y]==2)
		return 0;
	for(i=x-1;i>=1;i--)//�ж�Ҫ������λ�õ�x�е�0λ��
		if(m[i][y]==0)
			break;
	index=i;
	for(i=x-1;i>index;i--)//�жϴ�������������һ��0ʱ�����������û�з�����
		if(m[i][y]==2)
			return 0;
	for(i=y-1;i>=1;i--)//�ж�Ҫ������λ�õ�y�е�0λ��
		if(m[x][i]==0)
			break;
	index=i;
	for(i=y-1;i>index;i--)//�жϴ�������������һ��0ʱ�����������û�з�����
		if(m[x][i]==2)
			return 0;
	return 1;
}
void dfs(int x,int pos,int sum,int s){//������x�У�������һ����Ҫ����s������
	if(x==n+1){
		return;
	}
	if(sum==s){//����������һ�����
		count++;
		return;
	}
	int i,j;
	for(i=pos;i<=n;i++)//�жϵ�x�е�i�����
		if(check(x,i)&&m[x][i]!=0){
			m[x][i]++;
			dfs(x,i+1,sum+1,s);
			m[x][i]--;
		}
	dfs(++x,1,sum,s);
}
int main(){
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&m[i][j]);
	for(i=1;i<=n;i++){//����i�������ж��������
		dfs(1,1,0,i);
		printf("%d\n",count);
		count=0;
	}
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,map[9][9],cnt=0;
int check(int xx,int yy)//��x��,��y��λ�� 
{
	int i,j,t1=0,t2=0;
	if (map[xx][yy] == 2 || map[xx][yy] == 0) //�Ƕ�
	  return 1;
	for (i=xx-1; i>=1; i--) //�ҳ�0��λ��
	{
		if (map[i][yy] == 0)
		{
			t1 = i;
			break;
		 } 
	}
	for (i=xx-1; i>=1; i--)
	{
		if (map[i][yy] == 2)//�ҳ�2��λ�ã�2����������
		{
			t2 = i;
			break;
		}
	}
	if (t2 > t1) //2��0�Ͻ���˵�����ܷ�
	{
		return 1;
	}
	t1 = t2 = 0;
	for (i=yy-1; i>=1; i--)//ͬ�ϣ���2����0 ��λ��
	{
		if (map[xx][i] == 0)
		{
			t1 = i;
			break;
		}
	}
	for (i=yy-1; i>=1; i--)
	{
		if (map[xx][i] == 2)
		{
			t2 = i;
			break;
		}
	}
	if (t2 > t1)
	 return 1; 
	return 0; //���Է�
}
void dfs(int ss,int x,int sum,int pos)//��ss�����ӣ�x���±꣬sum�����ӣ�pos��¼��һ��ѭ��λ��
{
	int i,j,t;
	if (x > n)
	 return ;
	if (sum >= ss)//һ�ַ���
	{
		cnt++;
		return ;
	}
	for (i=pos; i<=n; i++)
	{
		if (check(x,i)) //�������У��ж��Ƿ���Է�����
		continue;
		t = map[x][i];
		map[x][i] = 2;
		dfs(ss,x,sum+1,i+1);//������
		map[x][i] = t;//���ݣ��ָ�ԭ��
	}
	dfs(ss,++x,sum,1);//����
}
int main()
{
	int i,j; 
	cin>>n;
	for (i=1; i<=n; i++)
	for (j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
	for (i=1; ;i++)
	{
		cnt=0;
		dfs(i,1,0,1);
		if (cnt==0)
		{
			break;
		}
		cout<<cnt<<endl;
	}
	return 0;
 }*/
