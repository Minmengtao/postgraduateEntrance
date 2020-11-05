#include<cstdio>
typedef struct Carpet{
	int a,b,g,k;
}Carpet;
int n,x,y;
Carpet c[10005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&c[i].a,&c[i].b,&c[i].g,&c[i].k);
	scanf("%d%d",&x,&y);
	int flag=-1;
	for(int j=0;j<n;j++)
		if(c[j].a<=x&&c[j].b<=y&&x<=(c[j].a+c[j].g)&&y<=(c[j].b+c[j].k))
			flag=j+1;
	printf("%d\n",flag);
	return 0;
}