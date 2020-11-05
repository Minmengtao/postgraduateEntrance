#include<stdio.h>
#include<stdlib.h>
typedef struct Student{
	int NO;
	char name[10];
	int year;
	int month;
	int grade[3];
}Student;
int main(){
	int m,i=0;
	scanf("%d\n",&m);
	Student *std;
	std=(Student*)malloc(sizeof(Student)*m);
	while(i<m){
		scanf("%d %s %d %d %d %d %d",&std[i].NO,std[i].name,&std[i].year,&std[i].month,
			&std[i].grade[0],&std[i].grade[1],&std[i].grade[2]);
		printf("%d %s %d/%d %d %d %d %.0f",std[i].NO,std[i].name,std[i].year,std[i].month,
			std[i].grade[0],std[i].grade[1],std[i].grade[2],(double)(std[i].grade[0]+std[i].grade[1]+std[i].grade[2])/3);
		i++;
	}
	return 0;
}