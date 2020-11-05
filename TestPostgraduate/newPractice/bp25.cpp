#include<cstdio>
__int64 stu[10][7]={0};
int main(){
	int ii=0,jj=0;
	__int64 max=-1,min=1000000;
	for(int i=0;i<10;i++){
		scanf("%I64d",&stu[i][0]);
		for(int j=1;j<=5;j++){
			scanf("%I64d",&stu[i][j]);
			stu[i][6]+=stu[i][j];
		}
		if(max<stu[i][6]){
			max=stu[i][6];
			ii=i;
		}
		if(min>stu[i][6]){
			min=stu[i][6];
			jj=i;
		}
	}
	printf("%I64d %I64d\n",stu[ii][0],max);
	printf("%I64d %I64d\n",stu[jj][0],min);
	return 0;
}