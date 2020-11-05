#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Problem{
	int time;
	int subscripe;
}Problem;
typedef struct Student{
	Problem *pro;
	char name[11];
	int subSum;
	int timeSum;
}Student;
int isContain(char str[],int length);
int order(Student std[],int k);
int main(){
	int m,n;
	scanf("%d %d\n",&m,&n);
	Student std[100];
	int k=0,kk;
	while(scanf("%s",std[k].name)!=EOF){
		int i=0;
		std[k].pro=(Problem*)malloc(sizeof(Problem)*m);
		std[k].subSum=0;
		std[k].timeSum=0;
		while(i<m){
			char str[10];
			scanf("%s",str);
			int length=strlen(str);
			if(isContain(str,length)==1){
				std[k].pro[i].time=atoi(str);
				std[k].pro[i].subscripe=0;
			}else{
				char str1[10]="",str2[10]="";
				int flag=0,j=0,dx1=0,dx2=0;
				while(j<length){
					if(str[j]!='('&&str[j]!=')'){
						switch(flag){
							case 0:str1[dx1++]=str[j];break;
							case 1:str2[dx2++]=str[j];break;
						}
					}else
						flag=1;
					j++;
				}
				std[k].pro[i].time=atoi(str1);
				std[k].pro[i].subscripe=atoi(str2);
			}
			if(std[k].pro[i].time>0){
				std[k].subSum++;
				std[k].timeSum+=std[k].pro[i].time+std[k].pro[i].subscripe*n;
			}
			i++;
		}
		k++;
	}
	order(std,k);
	for(kk=0;kk<k;kk++){
		printf("%-10s %2d %4d\n",std[kk].name,std[kk].subSum,std[kk].timeSum);
	}
	return 0;
}
int order(Student std[],int k){
	int i,j;
	Student temp;
	for(i=0;i<k-1;i++)
		for(j=i+1;j<k;j++)
			if(std[i].subSum<std[j].subSum||(std[i].subSum==std[j].subSum&&std[i].timeSum>std[j].timeSum)
			    ||(std[i].subSum==std[j].subSum&&std[i].timeSum==std[j].timeSum&&strcmp(std[i].name,std[j].name)>0)){
				temp=std[i];
				std[i]=std[j];
				std[j]=temp;
			}
	return 1;
}
int isContain(char str[],int length){
	int i=0;
	for(;i<length;i++)
		if(str[i]=='(')
			return 0;
	return 1;
}
