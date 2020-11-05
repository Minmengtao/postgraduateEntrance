#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char maze[55][55]={{'\0'}},dir[1005]={'\0'};
		int se,opt,i,j;
		scanf("%d",&se);
		for(i=1;i<=se;i++){
			char sign[55];
			scanf("%s",sign);
			for(j=1;j<=se;j++)
				maze[i][j]=sign[j-1];
		}
		scanf("%d",&opt);
		while(opt--){
			scanf("%s",dir);
			int x=1,y=1,len=strlen(dir);
			for(i=0;i<len;i++){
				switch(dir[i]){
					case 'L':y--;break;
					case 'R':y++;break;
					case 'U':x--;break;
					case 'D':x++;break;
				}
				if(x<1||x>se||y<1||y>se||maze[x][y]=='T'||maze[x][y]=='#')
					break;
			}
			if(x>se||y>se||x<1||y<1)
				printf("I am out!\n");
			else if(maze[x][y]=='T')
				printf("I get there!\n");
			else if(maze[x][y]=='#')
				printf("I am dizzy!\n");
			else
				printf("I have no idea!\n");
		}
	}
	return 0;
}