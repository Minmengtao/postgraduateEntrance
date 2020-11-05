#include<stdio.h>
int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		if(a==0&&b==0)
			break;
		int x,y;
		for(x=1;x<=100;x++)
			for(y=1;y<=100;y++)
				if(x*x-y*y==b*b-a*a)
					printf("%d %d\n",x,y);
		printf("\n");
	}
	return 0;
}