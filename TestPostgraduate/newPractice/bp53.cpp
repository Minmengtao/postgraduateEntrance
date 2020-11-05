#include<stdio.h>
int main(){
	int n,len;
	scanf("%d %d",&n,&len);
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
	if(k+1>=len)
		for(i=len-1;i>=0;i--)
			printf("%d",m[i]);
	else{
		for(i=len-1;i>k;i--)
			printf("0");
		for(i=k;i>=0;i--)
			printf("%d",m[i]);
	}
	printf("\n");
	return 0;
}