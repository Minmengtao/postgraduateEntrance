#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Student{
	char name[21];
	int voteNum;
}Student;
int contain(Student [],char [],int);
int main(){
	char str[21];
	int count=0,k=0;
	Student std[100];
	while(scanf("%s\n",str)!=EOF){
		count++;
		int i,len=strlen(str);
		for(i=0;i<len;i++)
			str[i]=tolower(str[i]);
		if(k==0||contain(std,str,k)==1){
			strcpy(std[k].name,str);
			std[k].voteNum=1;
			k++;
		}else{
			int j;
			for(j=0;j<k;j++)
				if(strcmp(std[j].name,str)==0){
					std[j].voteNum++;
					break;
				}
		}
		if(count==100)
			break;
	}
	int j;
	Student temp=std[0];
	if(k>=1)
	    for(j=1;j<k;j++)
	        if(temp.voteNum<std[j].voteNum)
	            temp=std[j];
	printf("%s %d\n",temp.name,temp.voteNum);
	return 0;
}
int contain(Student std[],char str[],int len){
	if(len==0)
		return 0;
	int i=0;
	while(i<len){
		if(strcmp(std[i].name,str)==0)
			return 0;
		i++;
	}
	return 1;
}
