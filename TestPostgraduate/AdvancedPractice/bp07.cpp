#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c;
	scanf("%d %d %d\n",&a,&b,&c);
	int delta=b*b-4*a*c;
	if(delta>0)
		printf("%.2f %.2f\n",(sqrt(delta)-b)/(2*a),(-sqrt(delta)-b)/(2*a));
	return 0;
}