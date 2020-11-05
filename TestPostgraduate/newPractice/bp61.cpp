#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int cnt=1,sig=a[0];
	for(int j=1;j<n;j++){
		if(sig==a[j])
			cnt++;
		else{
			printf("%d %d\n",sig,cnt);
			sig=a[j];
			cnt=1;
		}
	}
	printf("%d %d\n",sig,cnt);
	return 0;
}