#include<stdio.h>
#include<stdlib.h>
typedef struct S{
	int *num;
}S;
int main(){
	int n;
	S *s;
	while(scanf("%d",&n)!=EOF){
		s=(S*)malloc(sizeof(S)*(n+1));
		int i,j,k;
		for(i=1;i<n+1;i++)
			s[i].num=(int*)malloc(sizeof(int)*(n+1));
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				s[i].num[j]=0;
		char sign='r';
		i=1;j=1;
		int up_lim=0,down_lim=n+1,left_lim=0,right_lim=n+1;
		for(k=1;k<=n*n;k++){
			switch(sign){
				case 'u'://��up
					s[i].num[j]=k;
					i--;
					if(i==up_lim){//�������ϣ�ת����
						left_lim++;
						j++;
						i++;
						sign='r';
					}
					break;
				case 'd'://��down
					s[i].num[j]=k;
					i++;
					if(i==down_lim){//�������£�ת����
						right_lim--;
						j--;
						i--;
						sign='l';
					}
					break;
				case 'l'://��left
					s[i].num[j]=k;
					j--;
					if(j==left_lim){//��������ת����
						down_lim--;
						i--;
						j++;
						sign='u';
					}
					break;
				case 'r'://��right
					s[i].num[j]=k;
					j++;
					if(j==right_lim){//�������ң�ת����
						up_lim++;
						i++;
						j--;
						sign='d';
					}
					break;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d",s[i].num[j]);
				if(j<n)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
		free(s);
	}
	return 0;
}