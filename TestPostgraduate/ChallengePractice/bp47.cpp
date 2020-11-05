#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	char str[105];
	while(n--){
		scanf("%s",str);
		int len=strlen(str),i,a[6];
		for(i=0;i<6;i++)
			a[i]=0;
		for(i=0;i<len;i++){
			int j=i%6;
			a[j]+=str[i];
		}
		for(i=0;i<=5;i++){
			while(a[i]>=10){
				int num,sum=0;
				while(a[i]!=0){
					num=a[i]%10;
					sum+=num;
					a[i]=(a[i]-num)/10;
				}
				a[i]=sum;
			}
		}
		for(i=0;i<=5;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}