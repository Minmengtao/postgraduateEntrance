#include<stdio.h>
typedef struct Student{
	char name[20];
	int math;
	int politics;
}Student;
int main(){
	Student std[5];
	int i,max=0,sign;
	for(i=0;i<5;i++)
		scanf("%s %d %d",std[i].name,&std[i].math,&std[i].politics);
	for(i=0;i<5;i++){
		printf("%s %d\n",std[i].name,int(std[i].math+std[i].politics)/2);
		if(std[i].math>max){
			sign=i;
			max=std[i].math;
		}
	}
	printf("%s %d %d\n",std[sign].name,std[sign].math,std[sign].politics);
	return 0;
}