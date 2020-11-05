#include<cstdio>
int main(){
	int m,max;
	scanf("%d",&m);
	max=2;
	for(int i=2;i<=m;i++){
		if(i%2==0)
			continue;
		int in=i;
		while(in!=1){
			if(in%2==0)
				in/=2;
			else{
				in=in*3+1;
				if(in>max)
					max=in;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}