#include<stdio.h>
#include<string.h>
int order(long *num,int n);
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char str[1001];
		long num[501];
		scanf("%s",str);
		int len=strlen(str),i;
		while(len>=0){
			if(str[len-1]=='5')
				len--;
			else
				break;
		}
		for(i=0;i<=500;i++)
			num[i]=-1;
		int j=0;
		num[0]=0;
		for(i=0;i<len;i++){
			if(str[i]!='5'){
				num[j]=num[j]*10+(int)(str[i]-'0');
			}
			if(str[i]=='5'&&str[i+1]!='5'&&i<len-1){
				j++;
				num[j]=0;
			}
		}
		order(num,j);
		for(i=0;i<j;i++)
			printf("%ld ",num[i]);
		printf("%ld\n",num[i]);
	}
	return 0;
}
int order(long *num,int n){
	int i,j;
	for(i=0;i<=n;i++)
		for(j=i;j<=n;j++)
			if(num[i]>num[j]){
				long temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
	return 1;
}
