#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[4]={0};
int transfer(int x){
	a[0]=x/1000,a[2]=x%10,a[1]=(x-a[0]*1000)/100,a[3]=((x-a[2])/10)%10;
	//printf("%d %d %d %d",a[0],a[1],a[3],a[2]);
	sort(a,a+4);
	int x1=a[3]*1000+a[2]*100+a[1]*10+a[0],x2=a[0]*1000+a[1]*100+a[2]*10+a[3];
	return x1-x2;
}
int main(){
	scanf("%d",&n);
	int cnt=0,x=n;
	while(x!=6174){
		x=transfer(x);
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}