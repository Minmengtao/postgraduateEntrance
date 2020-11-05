#include<stdio.h>
#include<string.h>
int main(){
	char s[4];
	while(scanf("%s\n",s)!=EOF){
		if(strcmp(s,"Sat")==0)
			printf("Saturday");
		if(strcmp(s,"Mon")==0)
			printf("Monday");
		if(strcmp(s,"Tue")==0)
			printf("Tueday");
		if(strcmp(s,"Wed")==0)
			printf("Wednesday");
		if(strcmp(s,"Thu")==0)
			printf("Thursday");
		if(strcmp(s,"Fri")==0)
			printf("Friday");
		if(strcmp(s,"Sun")==0)
			printf("Sunday");
		printf("\n");
	}
	return 0;
}