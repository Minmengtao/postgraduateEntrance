#include<stdio.h>
#include<stdlib.h>
typedef struct Former{
	int begin;
	int end;
}Former;
int main(){
	int n,i=0,j;
	Former *former;
	scanf("%d",&n);
	former=(Former*)malloc(sizeof(Former)*n);
	while(i<n){
		scanf("%d %d",&former[i].begin,&former[i].end);
		i++;
	}
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(former[i].begin>former[j].end){
				Former temp=former[i];
				former[i]=former[j];
				former[j]=temp;
			}
	j=0;
	for(i=1;i<n;i++){
		if(former[i].begin<=former[j].end)
			former[j].end=former[i].end;
		else{
			j++;
			former[j]=former[i];
		}
	}
	int max=0,min=1000001,pre_end;
	for(i=0;i<=j;i++){
		if(former[i].end-former[i].begin>max)
			max=former[i].end-former[i].begin;
		if(i==0)
			pre_end=former[i].end;
		else
			if(former[i].begin-pre_end<min)
				min=former[i].begin-pre_end;
	}
	printf("%d %d\n",max,min);
	return 0;
}