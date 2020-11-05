#include<stdio.h>
#include<math.h>
int main(){
	int n,a[105],i;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		scanf("%d",&a[i]);
	int up_lim=0,down_lim=n;
	while(up_lim<=down_lim&&(a[up_lim]==0||a[down_lim]==0)){
		if(a[up_lim]==0)
			up_lim++;
		if(a[down_lim]==0)
			down_lim--;
	}
	for(i=up_lim;i<=down_lim;i++){
		if(a[i]>0){
			if(i!=up_lim)
				printf("+");
		}
		else if(a[i]==0)
			continue;
		else
			printf("-");
		if(i==n){
			printf("%d",abs(a[i]));
			break;
		}
		if(abs(a[i])==1){
			if(n-i==1)
				printf("x");
			else
				printf("x^%d",n-i);
		}else{
			if(n-i==1)
				printf("%dx",abs(a[i]));
			else
				printf("%dx^%d",abs(a[i]),n-i);
		}
	}
	printf("\n");
	return 0;
}
