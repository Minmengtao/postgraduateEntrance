#include<cstdio>
int main(){
	int a[100],len;
	while(~scanf("%d",&len)){
		int max=-100000,sec=-100000;
		for(int i=0;i<len;i++){
			scanf("%d",&a[i]);
			if(a[i]>max)
				max=a[i];
		}
		for(int j=0;j<len;j++)
			if(a[j]>sec&&a[j]<max)//Ѱ�ҵڶ������ֵ
				sec=a[j];
		if(sec==-100000)
			printf("none\n");
		else{
			printf("%d",sec);
			for(int k=0;k<len;k++)//��ӡλ��
				if(a[k]==sec)
					printf(" %d",k);
			printf("\n");
		}
	}
	return 0;
}