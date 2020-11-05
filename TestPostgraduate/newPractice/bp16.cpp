#include <stdio.h>
int sum=0,len,L,R;
void transfer(int n){
	while(n>0){
		int x=n%2;
		n/=2;
		if(x==1)
			sum++;
	}
}
int main(){
	scanf("%d%d",&L,&R);
	for(int i=L;i<=R;i++)
		transfer(i);
	printf("%d\n",sum);
	return 0;
}