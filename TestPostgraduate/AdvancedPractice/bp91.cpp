#include<stdio.h>
 
int res[1010];
int n,tot,len;
 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n+1;i++)//i��ʾ����
	{
		if (!(i%2))//������
			for (int j=0;j<i;j++) 
				res[++tot]=n-i+2+2*j;
		else//ż����
			for (int j=0;j<i;j++) 
				res[++tot]=n+i-2*j;
	}
	//���
	for (int i=2;i<=tot;i++){
		//������ʵ����д�����������ø���=��=
		len++;
		if (len%20==0) 
			len=0;
		if (!len) 
			printf("%d\n",res[i]);
		else 
			printf("%d ",res[i]);
	}
	for (int i=n;i>=1;i--){
		for (int j=(i*i-i)/2+1;j<=(i*i+i)/2;j++)//�õ��ǵȲ����еĺͣ�(����+β��)*����/2��������ԳƵĵ�i����
		{
			len++;
			if (len%20==0) 
				len=0;
			if (!len) 
				printf("%d\n",res[j]);
			else {
				if(i==1&&j==(i*i+i)/2)
					printf("%d",res[j]);
				else
					printf("%d ",res[j]);
			}
		}
	}
	return 0;
}