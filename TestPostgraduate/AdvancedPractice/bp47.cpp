#include<stdio.h>
#include<stdlib.h>
int main(){
	int T,*num,*signal;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		num=(int*)malloc(sizeof(int)*n);
		signal=(int*)malloc(sizeof(int)*n);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=0;i<n;i++)
			signal[i]=0;
		int count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(num[i]<signal[j]){
					signal[j]=num[i];
					break;
				}
				else{
					if(signal[j]!=0)
						continue;
					else{
						count++;
						signal[j]=num[i];
						break;
					}
				}
			}
		printf("%d\n",count);
	}
	return 0;
}


