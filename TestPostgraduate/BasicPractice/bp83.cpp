#include<stdio.h>
#include<stdlib.h>
typedef struct Student{
	int id;
	char name[10];
	char sex[10];
	int age;
	int grade;
}Student;
int swap(Student *std,int n);
int main(){
	Student *std;
	int N,i=0;
	scanf("%d\n",&N);
	std=(Student*)malloc(sizeof(Student)*N);
	while(i<N){
		scanf("%d %s %s %d %d\n",&std[i].id,std[i].name,std[i].sex,&std[i].age,&std[i].grade);
		i++;
	}
	swap(std,N);
	for(i=0;i<N-1;i++)
		printf("%d %s %s %d %d\n",std[i].id,std[i].name,std[i].sex,std[i].age,std[i].grade);
	printf("%d %s %s %d %d",std[i].id,std[i].name,std[i].sex,std[i].age,std[i].grade);
	return 0;
}
int swap(Student *std,int n){
	int i,j;
	Student temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(std[i].grade>std[j].grade){
				temp=std[i];
				std[i]=std[j];
				std[j]=temp;
			}
	return 1;
}