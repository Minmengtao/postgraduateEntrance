#include<stdio.h>
int main(){
	int i,N,avg,max,min,s;
	while(scanf("%d\n",&N)!=EOF){
		if(N>0&&N<20){
			i=1;
			avg=0;
			while(i<=N){
				scanf("%d\n",&s);
				if(s>=0&&s<=100){
					if(i==1){
						max=s;
						min=s;
					}
					if(s>max)
						max=s;
					if(min>s)
						min=s;
					avg+=s;
					i++;
				}
			}
			printf("%d %d %d\n",max,min,avg/N);
		}	
	}
	return 0;
}