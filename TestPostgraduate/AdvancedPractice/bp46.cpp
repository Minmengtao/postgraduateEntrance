#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
		int m,n,k=1;
		int *num1,*num2;
		while(k<=T){
			scanf("%d %d",&m,&n);
			num1=(int*)malloc(sizeof(int)*m);
			num2=(int*)malloc(sizeof(int)*n);
			int i;
			for(i=0;i<m;i++)
				scanf("%d",&num1[i]);
			for(i=0;i<n;i++)
				scanf("%d",&num2[i]);
			sort(num1,num1+m);
			int j,count=0;
			for(i=0;i<m;i++)
				for(j=0;j<n;j++){
					if(num1[i]!=num2[j]&&j==n-1)
						printf("%d ",num1[i]);
					if(num1[i]==num2[j]){
						count++;
						break;
					}
				}
			if(count==m)
				printf("NULL");
			printf("\n");
			free(num1);free(num2);
			k++;
		}
		
	
	return 0;
}
