#include<stdio.h>
int m,n,cube[100][100];
int main(){
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cube[i][j]);
	int in_x,in_y,step;
	char direction;
	scanf("%d %d %c %d",&in_x,&in_y,&direction,&step);
	for(i=0;i<step;i++){
		switch(direction){
			case 'U':
				if(cube[in_x][in_y]==1){
					cube[in_x][in_y]=0;
					direction='R';
					in_y++;
				}else{
					cube[in_x][in_y]=1;
					direction='L';
					in_y--;
				}
				break;
			case 'D':
				if(cube[in_x][in_y]==1){
					cube[in_x][in_y]=0;
					direction='L';
					in_y--;
				}else{
					cube[in_x][in_y]=1;
					direction='R';
					in_y++;
				}
				break;
			case 'L':
				if(cube[in_x][in_y]==1){
					cube[in_x][in_y]=0;
					direction='U';
					in_x--;
				}else{
					cube[in_x][in_y]=1;
					direction='D';
					in_x++;
				}
				break;
			case 'R':
				if(cube[in_x][in_y]==1){
					cube[in_x][in_y]=0;
					direction='D';
					in_x++;
				}else{
					cube[in_x][in_y]=1;
					direction='U';
					in_x--;
				}
				break;
		}
	}
	printf("%d %d\n",in_x,in_y);
	return 0;
}