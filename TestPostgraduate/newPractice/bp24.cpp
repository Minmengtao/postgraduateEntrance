#include<cstdio>
#include<algorithm>
using namespace std;
int a=0,b=0,c=0,d=0,e=0;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	int n,score[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&score[i]);
		if(score[i]>=90)
			a++;
		else if(score[i]>=80)
			b++;
		else if(score[i]>=70)
			c++;
		else if(score[i]>=60)
			d++;
		else
			e++;
	}
	printf("%d %d %d %d %d\n",a,b,c,d,e);
	int m=max(a,max(b,max(c,max(d,e)))),sig[100],len=0;
	printf("%d\n",m);
	for(int j=0;j<n;j++){
		if(m==a&&score[j]>=90)
			sig[len++]=score[j];
		if(m==b&&score[j]>=80&&score[j]<90)
			sig[len++]=score[j];
		if(m==c&&score[j]>=70&&score[j]<80)
			sig[len++]=score[j];
		if(m==d&&score[j]>=60&&score[j]<70)
			sig[len++]=score[j];
		if(m==e&&score[j]<60)
			sig[len++]=score[j];
	}
	sort(sig,sig+len);
	int k=len-1;
	while(k>0)
		printf("%d ",sig[k--]);
	printf("%d\n",sig[k]);
	return 0;
}
