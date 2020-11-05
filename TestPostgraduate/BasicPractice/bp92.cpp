#include<stdio.h>
#include<stdlib.h>
typedef struct Friend{
	char name[11];
	int year;
	int month;
	int day;
}Friend;
int order(Friend *f,int n);
int main(){
	Friend *f;
	int n,i=0;
	scanf("%d\n",&n);
	f=(Friend*)malloc(sizeof(Friend)*n);
	while(i<n){
		scanf("%s %d %d %d\n",f[i].name,&f[i].year,&f[i].month,&f[i].day);
		i++;
	}
	order(f,n);
	for(i=0;i<n;i++){
		printf("%s %d-",f[i].name,f[i].year);
		if(f[i].month>9)
			printf("%d-",f[i].month);
		else
			printf("0%d-",f[i].month);
		if(f[i].day>9)
			printf("%d",f[i].day);
		else
			printf("0%d",f[i].day);
		printf("\n");
	}
	return 0;
}
int order(Friend *f,int n){
	Friend temp;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if(f[i].month>f[j].month||((f[i].month==f[j].month)&&(f[i].day>f[j].day))){
				temp=f[i];
				f[i]=f[j];
				f[j]=temp;
			}
	return 1;
}