#include<cstdio>
#include<algorithm>
using namespace std;

int a[1005],b[1005],c[1005],n,m;
int main(){
	int i,j,len=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	scanf("%d",&m);
	for(j=0;j<m;j++)
		scanf("%d",&b[j]);
	sort(b,b+m);
	i=0;j=0;
	while(i<n&&j<m){
		if(a[i]==b[j]){
			printf("%d ",a[i]);
			c[len++]=a[i];
			i++;j++;
		}
		else if(a[i]>b[j])
			j++;
		else
			i++;
	}
	if(len>0)
		printf("\n");

	i=0;j=0;
	while(i<n&&j<m){
		if(a[i]==b[j]){
			printf("%d ",a[i]);
			i++;j++;
		}else if(a[i]>b[j])
			printf("%d ",b[j++]);
		else
			printf("%d ",a[i++]);
	}
	while(i<n)
		printf("%d ",a[i++]);
	while(j<m)
		printf("%d ",b[j++]);
	printf("\n");

	int z=0;
	for(int k=0;k<n;k++){
		if(len>0){
			if(a[k]==c[z])
				z++;
			else
				printf("%d ",a[k]);
		}else
			printf("%d ",a[k]);
	}
	printf("\n");
	return 0;
}