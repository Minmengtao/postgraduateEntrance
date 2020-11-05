#include<stdio.h>
#include<string.h>
typedef struct File{
	char FileName[100];
	int FileType;
	char FileInfo[100];
}File;
File file[1001];
int len=0;
int contain(char *name){
	int i;
	for(i=0;i<len;i++)
		if(strcmp(file[i].FileName,name)==0)
			return i;
	return -1;
}
int main(){
	char demand[10];
	while(scanf("%s",demand)!=EOF){
		if(strcmp(demand,"create")==0){
			char name[100],info[100];
			int type;
			scanf("%s %d %s",name,&type,info);
			int index=contain(name);
			if(index==-1){//name²»ÔÚfileÖÐ
				strcpy(file[len].FileName,name);
				file[len].FileType=type;
				strcpy(file[len].FileInfo,info);
				len++;
			}else{
				file[index].FileType=type;
				strcpy(file[index].FileInfo,info);
			}
		}
		if(strcmp(demand,"open")==0){
			char temp[100];
			scanf("%s",temp);
			int i=0;
			while(i<len){
				if(strcmp(file[i].FileName,temp)==0){
					if(file[i].FileType){
						strcpy(temp,file[i].FileInfo);
						i=-1;
					}
					else{
						printf("%s\n",file[i].FileInfo);
						break;
					}
				}
				i++;
			}
		}
		if(strcmp(demand,"exit")==0)
			break;
	}
	return 0;
}