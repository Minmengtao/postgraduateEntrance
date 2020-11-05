#include<cstdio>
#include<algorithm>
using namespace std;

int n,win[7],num[6]={0};
int main(){
	scanf("%d",&n);
	int i;
	for(i=0;i<7;i++)
		scanf("%d",&win[i]);
	sort(win,win+7);
	while(n--){
		int a[7];
		for(i=0;i<7;i++)
			scanf("%d",&a[i]);
		sort(a,a+7);
		int j=0,k=0,cnt=0;
		while(j<7&&k<7){
			if(win[j]==a[k]){
				cnt++;
				j++;k++;
			}else if(win[j]>a[k])
				k++;
			else
				j++;
		}
		num[7-cnt]++;
	}
	for(i=0;i<7;i++)
		printf("%d ",num[i]);
	printf("\n");
	return 0;
}
