#include<stdio.h>
#include<stdlib.h>
typedef struct Int{
	int *inz;
}Int;
int main(){
	Int *in;
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	in=(Int*)malloc(sizeof(Int)*m);
	for(i=0;i<m;i++)
		in[i].inz=(int*)malloc(sizeof(int)*n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&in[i].inz[j]);
	int l_lim=-1,r_lim=n,u_lim=-1,d_lim=m,k;
	i=0;j=0;
	char si='d';
	for(k=0;k<m*n-1;k++){
		printf("%d ",in[i].inz[j]);
		switch(si){
			case 'l':
				j--;
				if(j==l_lim){
					si='d';
					i++;
					j++;
					u_lim++;
				}
				break;
			case 'r':
				j++;
				if(j==r_lim){
					si='u';
					j--;
					i--;
					d_lim--;
				}
				break;
			case 'u':
				i--;
				if(i==u_lim){
					si='l';
					i++;
					j--;
					r_lim--;
				}
				break;
			case 'd':
				i++;
				if(i==d_lim){
					si='r';
					i--;
					j++;
					l_lim++;
				}
				break;
		}
	}
	printf("%d\n",in[i].inz[j]);
	return 0;
}