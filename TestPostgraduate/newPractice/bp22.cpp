#include<cstdio>
#include<algorithm>
using namespace std;

int m,n,dragon[20005],knight[20005];
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&dragon[i]);
		sort(dragon,dragon+n);
		for(int j=0;j<m;j++)
			scanf("%d",&knight[j]);
		sort(knight,knight+m);
		int x=0,y=0,sum=0;
		while(x<n&&y<m){
			if(dragon[x]>knight[y])
				y++;
			else{
				sum+=knight[y];
				x++;y++;
			}
		}
		if(x!=n)
			printf("Lose!\n");
		else
			printf("%d\n",sum);
	}
	return 0;
}
	