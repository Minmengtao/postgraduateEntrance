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
			if(a[j]>sec&&a[j]<max)//寻找第二大的数值
				sec=a[j];
		if(sec==-100000)
			printf("none\n");
		else{
			printf("%d",sec);
			for(int k=0;k<len;k++)//打印位置
				if(a[k]==sec)
					printf(" %d",k);
			printf("\n");
		}
	}
	return 0;
}