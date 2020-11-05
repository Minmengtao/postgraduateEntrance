#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[105];
int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int j;
		for(j=0;j<n;j+=2)
			if(a[j]!=a[j+1])
				break;
		printf("%d\n",a[j]);
	}
	return 0;
}