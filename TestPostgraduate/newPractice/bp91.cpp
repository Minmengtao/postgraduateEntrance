#include <iostream>
#include <algorithm>
using namespace std;
long n,a[25],t,cnt=0,sum=0;
long b[25]={0},len=0;
void dfs(int x){
	if(sum>t||x>n)
		return;
	if(sum==t&&len>0){
		for(int i=0;i<len;i++)
			cout << b[i] << " ";
		cout << endl;
		cnt++;
		return;
	}
	for(int i=x;i<n;i++){
		sum+=a[i];
		b[len++]=a[i];
		dfs(i+1);
		sum-=a[i];
		b[len--]=0;
	}
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cin >> t;
	sort(a,a+n);
	dfs(0);
   	cout << cnt;
   	return 0;
}