#include<cstdio>
#include<cstring>
char a[10005],b[10005];
int n1[10005]={0},n2[10005]={0},n3[20005]={0};
int main(){
	scanf("%s%s",a,b);
    int len1=strlen(a),len2=strlen(b);
	int max=len1+len2,i,j;
	for(i=0,j=len1-1;i<len1;i++,j--)
		n1[i]=a[j]-'0';
	for(i=0,j=len2-1;i<len2;i++,j--)
		n2[i]=b[j]-'0';
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
			n3[i+j]+=n1[i]*n2[j];
	for(i=0;i<max;i++)
		if(n3[i]>=10){
			n3[i+1]+=n3[i]/10;
			n3[i]%=10;
		}
	while(n3[max-1]==0)
		if(n3[max-1]==0)
			max--;
	for(i=max-1;i>=0;i--)
		printf("%d",n3[i]);
	printf("\n");
    return 0;
}
