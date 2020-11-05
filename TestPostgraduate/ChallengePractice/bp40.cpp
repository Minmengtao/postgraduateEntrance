#include<cstdio>
#include<algorithm>
using namespace std;
int n,sig[10]={0};
int judge(int x){
	int count=-1;
	for(int i=0;i<10;i++)
		if(sig[i]==0){
			count++;
			if(count==x){
				sig[i]=1;
				return i;
			}
		}
	return -1;
}
void dfs(int x,int num){//ÅĞ¶ÏµÚxÎ»Êı
	if(x==11)
		return;
	printf("%d",judge(n/num));
	n=n%num;
	if(x<10)
		num/=(10-x);
	else
		num=0;
	dfs(x+1,num);
}
int main(){
	scanf("%d",&n);
	n--;
	int num=1;
	for(int i=1;i<=9;i++)
		num*=i;
	dfs(1,num);
	printf("\n");
	return 0;
}