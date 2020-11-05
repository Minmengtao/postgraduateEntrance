#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,k,count=0;
		for(i=1;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++){
					if(i+j>k&&i+k>j&&j+k>i&&i+j+k==n)
						count++;
				}
		printf("%d\n",count);
	}
	return 0;
}