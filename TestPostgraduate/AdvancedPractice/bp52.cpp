#include<stdio.h>
#include<math.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		for(i=1;i<=10000;i++){
			double num=0.0;
			int j=i,count=0;
			while(j!=0){
				num=num+(j%2)*pow(10,count);
				j=j/2;
				count++;
			}
			int s=num;
			if(s%n==0){
				printf("%d\n",s);
				break;
			}
		}
	}
	return 0;
}