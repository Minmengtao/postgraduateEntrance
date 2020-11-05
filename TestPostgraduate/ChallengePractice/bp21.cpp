#include<stdio.h>
int main(){
	int i,j,n,from[1002],temp=1,max;
	scanf("%d",&n);
	for(i=1;i<=n;i++)//from[1]Ò»¶¨Îª0
		scanf("%d",&from[i]);
	for(i=n;i>=temp;i--){
		if(from[i]<i){
			max=1;
			j=from[i];
			while(from[j]>0&&from[j]<j){
				max++;
				j=from[j];
			}
			if(from[j]==0){
				max++;
				if(max>temp)
					temp=max;
			}
		}
	}
	printf("%d\n",temp);
	return 0;
}