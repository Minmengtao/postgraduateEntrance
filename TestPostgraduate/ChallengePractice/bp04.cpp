#include<stdio.h>
int main(){
	int n;
	while(~scanf("%d",&n)){
		int m[100000],i,j,s,k=0,a;
		m[0]=1;
		for(i=1;i<=n;i++){
			s=0;
			for(j=0;j<=k;j++){
				a=m[j]*i+s;
				m[j]=a%10;
				s=a/10;
			}
			while(s!=0){
				k++;
				m[k]=s%10;
				s=s/10;
			}
		}
		for(i=k;i>=0;i--)
			printf("%d",m[i]);
		printf("\n");
	}
	return 0;
}