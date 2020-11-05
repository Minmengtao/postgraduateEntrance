#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Motor{
	char scale[10];
	char color[20];
	char mada[10];
}Motor;
typedef struct Need{
	char scale[10];
}Need;
int order(Motor *motor,int m);
int main(){
	int n,m;
	Need *need;
	Motor *motor;
	while(scanf("%d %d",&n,&m)!=EOF){
		need=(Need*)malloc(sizeof(Need)*n);
		motor=(Motor*)malloc(sizeof(Motor)*m);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%s",need[i].scale);
		for(i=0;i<m;i++)
			scanf("%s %s %s",motor[i].scale,motor[i].color,motor[i].mada);
		int count=0;
		order(motor,m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(strcmp(need[i].scale,motor[j].scale)==0){
					printf("%s %s %s\n",motor[i].scale,motor[i].color,motor[i].mada);
					count++;
				}
		if(count==0)
			printf("Not found!\n");
		free(need);
		free(motor);
	}
	return 0;
}
int order(Motor *motor,int m){
	int i,j;
	for(i=0;i<m;i++)
		for(j=i;j<m;j++)
			if((motor[i].scale[0]>motor[j].scale[0])||(motor[i].scale[0]==motor[j].scale[0]&&
				motor[i].scale[1]>motor[j].scale[1])){
				Motor temp=motor[i];
				motor[i]=motor[j];
				motor[j]=temp;
			}
	return 1;
}
