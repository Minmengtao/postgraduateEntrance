#include <cstdio>

typedef struct per{
	int w,h;
	char name[30];
}per;
per p[1005],qu[1005];
int a,b,c,d,n,len=0;
void sort(){
	for(int i=0;i<len;i++)
		for(int j=i;j<len;j++)
			if(qu[i].h>qu[j].h||(qu[i].h==qu[j].h&&qu[i].w>qu[j].w)){
				per temp=qu[i];
				qu[i]=qu[j];
				qu[j]=temp;
			}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s%d%d",p[i].name,&p[i].h,&p[i].w);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<n;i++)
		if((p[i].h>=a&&p[i].h<=b)&&(p[i].w>=c&&p[i].w<=d))
			qu[len++]=p[i];
	if(len==0)
		printf("No\n");
	else{
		sort();
		for(int i=0;i<len;i++)
			printf("%s %d %d\n",qu[i].name,qu[i].h,qu[i].w);
	}
	return 0;
}