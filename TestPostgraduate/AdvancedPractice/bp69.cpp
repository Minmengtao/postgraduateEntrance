#include<stdio.h>
#include<stdlib.h>
typedef struct Student{
	char name[10000];
	int grade_exam;
	int grade_class;
	char isOfficer;
	char isWestern;
	int issue;
	int salary;
}Student;
int order(Student *std,int N);
int main(){
	Student *std;
	int N;
	while(scanf("%d",&N)!=EOF){
		std=(Student*)malloc(sizeof(Student)*N);
		int i,salary=0;
		for(i=0;i<N;i++){
			std[i].salary=0;
			scanf("%s %d %d %c %c %d",std[i].name,&std[i].grade_exam,&std[i].grade_class,
				&std[i].isOfficer,&std[i].isWestern,&std[i].issue);
			if(std[i].grade_exam>80&&std[i].issue>=1)
				std[i].salary+=8000;
			if(std[i].grade_exam>85&&std[i].grade_class>80)
				std[i].salary+=4000;
			if(std[i].grade_exam>90)
				std[i].salary+=2000;
			if(std[i].grade_exam>85&&std[i].isWestern=='Y')
				std[i].salary+=1000;
			if(std[i].grade_class>80&&std[i].isOfficer=='Y')
				std[i].salary+=850;
			salary+=std[i].salary;
		}
		order(std,N);
		printf("%s\n%d\n%d\n\n",std[0].name,std[0].salary,salary);
		free(std);
	}
	return 0;
}
int order(Student *std,int N){
	int i,j;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++)
			if(std[i].salary<std[j].salary){
				Student temp=std[i];
				std[i]=std[j];
				std[j]=temp;
			}
	return 1;
}
