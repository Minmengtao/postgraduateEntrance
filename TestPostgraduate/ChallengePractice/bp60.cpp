#include<stdio.h>
char a[125][125],n;
int main(){
	while(~scanf("%d",&n)){
		int m=n*4+5,i,j;
		a[0][0]='.';
		a[1][0]='.';
		a[1][1]='.';
		for(i=2;i<=(m+1)/2-1;i++){
			a[i][0]='$';
			for(j=1;j<=(m+1)/2-1&&j<=i;j++){
				if(a[i-1][j-1]=='.')
					a[i][j]='$';
				if(a[i-1][j-1]=='$')
					a[i][j]='.';
			}
		}
		for(i=0;i<=(m+1)/2-1;i++)//¸´¿ÌÐ±¶Ô½ÇÏß
			for(j=0;j<=(m+1)/2-1&&j<=i;j++)
				a[j][i]=a[i][j];
		for(i=0;i<=(m+1)/2-1;i++)//¸´¿ÌÊúÏß
			for(j=0;j<=(m+1)/2-1;j++)
				a[i][m-j-1]=a[i][j];
		for(i=0;i<=(m+1)/2-1;i++)//¸´¿ÌºáÏß
			for(j=0;j<m;j++)
				a[m-1-i][j]=a[i][j];
		for(i=0;i<m;i++){
			for(j=0;j<m;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}