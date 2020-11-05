#include<cstdio>
#include<cmath>
int coor[3][2],x1,x2,x3;
int main(){
	for(int i=0;i<3;i++)
		scanf("%d%d",&coor[i][0],&coor[i][1]);
	x1=(coor[0][0]-coor[1][0])*(coor[0][0]-coor[1][0])+(coor[0][1]-coor[1][1])*(coor[0][1]-coor[1][1]);
	x2=(coor[0][0]-coor[2][0])*(coor[0][0]-coor[2][0])+(coor[0][1]-coor[2][1])*(coor[0][1]-coor[2][1]);
	x3=(coor[1][0]-coor[2][0])*(coor[1][0]-coor[2][0])+(coor[2][1]-coor[1][1])*(coor[2][1]-coor[1][1]);
	if(x1==x2)
		printf("1\n");
	else if(x1==x3)
		printf("2\n");
	else if(x2==x3)
		printf("3\n");
	else
		printf("no center\n");
	return 0;
}
