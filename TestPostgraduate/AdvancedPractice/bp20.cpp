#include<stdio.h>
int main(){
	int a,b,T;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d %d\n",&a,&b);
		int i,count=0;
		for(i=0;i<=99;i++){
			int x=a*100+i;
			if(x%b==0){
				count++;
				if(count==1){
					if(i>=0&&i<=9)
						printf("0%d",i);
					else
						printf("%d",i);
				}
				else{
					if(i>=0&&i<=9)
						printf(" 0%d",i);
					else
						printf(" %d",i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}