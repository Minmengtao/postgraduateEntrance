#include<cstdio>
int main(){
	int cnt=0,score[10];
	double avg=0;
	for(int i=0;i<10;i++){
		scanf("%d",&score[i]);
		avg+=score[i];
	}
	avg/=10;
	printf("%.1f\n",avg);
	for(int j=0;j<10;j++)
		if(score[j]>avg)
			printf("%d ",score[j]);
	printf("\n");
	return 0;
}