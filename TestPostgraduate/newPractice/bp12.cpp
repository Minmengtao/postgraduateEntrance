#include<cstdio>
int num[5]={0};
int main(){
	int a,b,c,d,i=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(a-2>=0&&b-1>=0&&d-2>=0){
		num[i]++;
		a-=2;b--;d-=2;
	}
	i++;
	while(a-1>=0&&b-1>=0&&c-1>=0&&d-1>=0){
		num[i]++;
		a--;b--;c--;d--;
	}
	i++;
	while(c-2>=0&&d-1>=0){
		num[i]++;
		c-=2;d--;
	}
	i++;
	while(b-3>=0){
		num[i]++;
		b-=3;
	}
	i++;
	while(a-1>=0&&d-1>=0){
		num[i]++;
		a--;d--;
	}
	for(int j=0;j<5;j++)
		printf("%d\n",num[j]);
	return 0;
}