#include<stdio.h>
int main(){
	int T=10,n;
	while(T--){
		scanf("%d",&n);
		if(n==0)
			break;
		int full=1,empty,temp=0;
		empty=n;
		while(full!=0){
			full=empty/3;
			temp=temp+full;
			empty=empty%3+full;
		}
		if(empty==2)
			temp++;
		printf("%d\n",temp);
	}
	return 0;
}