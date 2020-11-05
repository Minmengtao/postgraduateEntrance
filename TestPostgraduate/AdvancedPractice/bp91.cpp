#include<stdio.h>
 
int res[1010];
int n,tot,len;
 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n+1;i++)//i表示组数
	{
		if (!(i%2))//奇数组
			for (int j=0;j<i;j++) 
				res[++tot]=n-i+2+2*j;
		else//偶数组
			for (int j=0;j<i;j++) 
				res[++tot]=n+i-2*j;
	}
	//输出
	for (int i=2;i<=tot;i++){
		//这里其实可以写个函数，懒得改了=。=
		len++;
		if (len%20==0) 
			len=0;
		if (!len) 
			printf("%d\n",res[i]);
		else 
			printf("%d ",res[i]);
	}
	for (int i=n;i>=1;i--){
		for (int j=(i*i-i)/2+1;j<=(i*i+i)/2;j++)//用的是等差数列的和，(首项+尾项)*项数/2，来输出对称的第i组数
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