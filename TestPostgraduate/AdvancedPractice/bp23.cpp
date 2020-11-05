#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,m,k=0,a,w[40000];
		w[0]=1;
		for(i=1;i<=n;i++){
			m=0;
			for(j=0;j<=k;j++){
				a=w[j]*i+m;
				m=a/10;
				w[j]=a%10;
			}
			while(m>0){
				k++;
				w[k]=m%10;
				m=m/10;
			}
		}
		for(i=0;i<=k;i++)
			if(w[i]!=0){
				printf("%d",w[i]);
				break;
			}
	    printf("\n");
	}
	return 0;
}
