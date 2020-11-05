#include<stdio.h>
int main(){
	int sign[3][3];
	int i,j,k,ii,jj,kk;
	int x,y,z,min=300;
	scanf("%d %d %d",&x,&y,&z);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&sign[i][j]);
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			for(k=0;k<100;k++){
				if(i+j+k==0)
					continue;
				int xx=i*sign[0][0]+j*sign[1][0]+k*sign[2][0];
				int yy=i*sign[0][1]+j*sign[1][1]+k*sign[2][1];
				int zz=i*sign[0][2]+j*sign[1][2]+k*sign[2][2];
				if(xx*y==yy*x&&xx*z==zz*x&&yy*z==zz*y&&min>i+j+k){
					ii=i;jj=j;kk=k;
					if((ii*sign[0][0]+jj*sign[1][0]+kk*sign[2][0])/x!=0)
						min=i+j+k;
				}
			}
	if(min==300)
		printf("NONE\n");
	else
		printf("%d %d %d %d\n",ii,jj,kk,(ii*sign[0][0]+jj*sign[1][0]+kk*sign[2][0])/x);
	return 0;
}