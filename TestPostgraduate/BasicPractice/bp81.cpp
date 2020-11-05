#include<stdio.h>
#include<string.h>
typedef struct Candidate{
	char *name;
	int count;
}Can;
int main(){
	Can can[3];
	can[0].name="li";can[0].count=0;
	can[1].name="zhang";can[1].count=0;
	can[2].name="wang";can[2].count=0;
	int k=10,count=0,i;
	char s[10];
	while(k--){
		scanf("%s\n",s);
		if(strcmp(can[0].name,s)==0)
			can[0].count++;
		else if(strcmp(can[1].name,s)==0)
			can[1].count++;
		else if(strcmp(can[2].name,s)==0)
			can[2].count++;
		else count++;
	}
	for(i=0;i<3;i++)
		printf("%s:%d\n",can[i].name,can[i].count);
	printf("Wrong election:%d\n",count);
	return 0;
}
