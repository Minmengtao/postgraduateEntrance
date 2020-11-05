#include<stdio.h>
int main(){
	int N,i=0;;
	int max1=0,max2=0,max3=0;
	int min1=0,min2=0,min3=0;
	int Y,M,D;
	scanf("%d\n",&N);
	if(N>0&&N<20)
		while(i<N){
			scanf("%d %d %d\n",&Y,&M,&D);
			if(Y>=1&&Y<=2015&&M>=1&&M<=12&&D>=1&&D<=31){
				if(i==0||max1<Y||(max1==Y&&max2<M)||(max1==Y&&max2==M&&max3<D)){
					max1=Y;
					max2=M;
					max3=D;
				}
				if(i==0||min1>Y||(min1==Y&&min2>M)||(min1==Y&&min2==M&&min3>D)){
					min1=Y;
					min2=M;
					min3=D;
				}
			}
			i++;
		}
	printf("%d %d %d\n",max1,max2,max3);
	printf("%d %d %d\n",min1,min2,min3);

	return 0;
}