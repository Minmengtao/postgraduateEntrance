#include<stdio.h>
int a[55],n,countStep=0;
int isZero(){
	int i;
	for(i=0;i<n;i++)
		if(a[i]!=0)
			return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(isZero()){
		int flag=0;
		for(i=0;i<n;i++){
			if(a[i]!=0&&a[i]%2!=0){
				a[i]--;
				countStep++;
			}
			if(a[i]%2==0&&a[i]!=0){
				a[i]/=2;
				flag=1;
			}
		}
		countStep+=flag;
	}
	printf("%d\n",countStep);
	return 0;
}