#include<stdio.h>
int A[510][510],n,m;
int main(){
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&A[i][j]);
	return 0;
}