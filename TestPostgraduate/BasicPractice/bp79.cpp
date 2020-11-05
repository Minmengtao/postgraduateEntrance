#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order(char *s,int len);
int locate(char *s,char sign,int len,int *isT);
int main(){
	char s[11],str[11];
	int *isT;
	while(scanf("%s\n",s)!=EOF){
		int len=strlen(s),i=0,j=0,k=0;
		isT=(int*)malloc(sizeof(int)*len);
		for(;k<len;k++)
			isT[k]=0;
		strcpy(str,s);
		order(str,len);
		for(;i<len;i++){
			int site=locate(s,str[i],len,isT);
			for(j=site;j<len;j++)
				printf("%c",s[j]);
			printf("\n");
		}
	}
	return 0;
}
int locate(char *s,char sign,int len,int *isT){
	int i=0,j,count=0,*signal,k=0,cumcm;
	signal=(int*)malloc(sizeof(int)*len);
	while(i<len){
		if(s[i]==sign&&isT[i]==0){
			count++;
			signal[k++]=i;
		}
		i++;
	}
	if(count==1){
		isT[i]=1;
		return signal[0];
	}else{
		int mcm=signal[0];
		j=0;
		while(j<k){
			i=signal[j];
			printf("#%d %d# ",mcm,i);
			cumcm=0;
			while(mcm+cumcm<len&&i<len){
				if(s[mcm+cumcm]>s[i]){
				    printf("@%c %c %d %d@\n",s[mcm+cumcm],s[i],mcm+cumcm,i);
					mcm=signal[j];
					break;
				}
				cumcm++;
				i++;
			}
			if(i==len&&mcm+cumcm<len)
				mcm=signal[j];
			j++;
		}
		isT[mcm]=1;
		return mcm;
	}
}
int order(char *s,int len){
	int i,j;
	char temp;
	for(i=0;i<len-1;i++)
		for(j=i+1;j<len;j++)
			if(s[i]>s[j]){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	return 1;
}
