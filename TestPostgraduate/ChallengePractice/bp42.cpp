#include<cstdio>
int a[20][2],len,ans;
void dfs(){
}
int main(){
	int count=0;
	while(~scanf("%d",&len)){
		if(!len)
			break;
		int i=0;
		while(flag){
			scanf("%d%d",&a[len][0],&a[len][1]);
			if(a[len][0]==-1&&a[len][1]==-1)
				break;
			len++;
		}
		ans=0;
		dfs();
		count++;
		printf("Set %d: Minimum links to open is %d\n",count,ans);
	}
	return 0;
}
