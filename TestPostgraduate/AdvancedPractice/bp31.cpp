#include<stdio.h>
int main(){
	int n;
	int num[110];
	while(scanf("%d",&n)!=EOF){
		int i,number;
		for(i=1;i<=109;i++)
			num[i]=0;
		for(i=0;i<n;i++){
			scanf("%d",&number);
			num[number]++;
		}
		int highestTimes=0,highest;
		for(i=1;i<=109;i++)
			if(highestTimes<num[i]){
				highest=i;
				highestTimes=num[i];
			}
		printf("%d\n",highest);
	}
	return 0;
}