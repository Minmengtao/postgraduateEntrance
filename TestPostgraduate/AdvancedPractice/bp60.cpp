#include<stdio.h>
int main(){
	int num[5][5];
	int ii;
	while(scanf("%d",&ii)!=EOF){
		num[0][0]=ii;
		int i,j,k,m,n;
		for(i=1;i<=4;i++)
			scanf("%d",&num[0][i]);
		for(i=1;i<5;i++)
			for(j=0;j<5;j++)
				scanf("%d",&num[i][j]);
		int max=0;
		i=1;j=1;k=1;m=1;n=1;
		while(i<=5){
			while(j<=5){
				if(j==i){
					j++;
					continue;
				}
				while(k<=5){
					if(k==j||k==i){
						k++;
						continue;
					}
					while(m<=5){
						if(m==k||m==j||m==i){
							m++;
							continue;
						}
						while(n<=5){
							if(n==m||n==k||n==j||n==i){
								n++;
								continue;
							}
							int temp=num[0][i-1]+num[1][j-1]+num[2][k-1]+num[3][m-1]+num[4][n-1];
							if(temp>max){
							    printf("%d %d %d %d %d\n",i,j,k,m,n);
								max=temp;
							}
							n++;
						}
						m++;
						n=1;
					}
					k++;
					m=1;
				}
				j++;
				k=1;
			}
			i++;
			j=1;
		}
		printf("%d\n",max);
	}
	return 0;
}