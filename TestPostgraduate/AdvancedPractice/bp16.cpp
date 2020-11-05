#include<stdio.h>
int main(){
	int n;
	while(scanf("%d\n",&n)!=EOF){
		int x_sign,count_sign=0;
		int i=0,x,x_pre,count_pre;
		scanf("%d",&x);
		x_pre=x;
		count_pre=1;
		while(i<n-1){
			scanf("%d",&x);
			if(x==x_pre)
				count_pre++;
			else{
				if(count_sign<count_pre){
					x_sign=x_pre;
					count_sign=count_pre;
				}
				x_pre=x;
				count_pre=1;
			}
			i++;
		}
		if(count_sign==0){
		    x_sign=x_pre;
			count_sign=count_pre;
		}
		printf("%d %d\n",x_sign,count_sign);
	}
	return 0;
}