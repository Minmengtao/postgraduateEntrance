#include<cstdio>
int bin,num;
char decTo(int x){
	if(x>=0&&x<=9)
		return x+'0';
	else
		return x-10+'A';
}
void bi(int n){
	if(n==0)
		return;
	char s=decTo(n%bin);
	bi(n/bin);
	printf("%c",s);
}
int main(){
	while(~scanf("%d %d",&num,&bin)){
		if(num==0)
			printf("0");
		else
			bi(num);
		printf("\n");
	}
	return 0;
}