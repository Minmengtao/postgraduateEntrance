#include <stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,temp;
		scanf("%d",&N);
		scanf("%d",&temp);
		int or=temp,min=temp,sum=temp;			//sum为异或和 account为正常和
		N--;
		while(N--){
			scanf("%d",&temp);
			or^=temp;
			sum+=temp;
			if(temp<min){
				min=temp; 
			}
		}
		if(or)
			printf("NO\n");
		else
			printf("%d\n",sum-min);
	}
	return 0;
} 