#include<stdio.h>
int main(){
    int s[10][10];
    int n;
    while(scanf("%d",&n)!=EOF){
        int i,j,k;
        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
                s[i][j]=0;
		char sign='d';
		i=4;j=4;
		int u_l=i,l_l=i,d_l=i,r_l=i;
		for(k=1;k<=n;k++){
			s[i][j]=k;
			switch(sign){
				case 'u'://��
					i--;
					if(i==u_l-2){//�ִ����ϣ�ת����
						u_l--;
						i++;
						j--;
						sign='l';
					}
					break;
				case 'd'://��
					i++;
					if(i==d_l+2){//�ִ����£�ת����
						d_l++;
						i--;
						j++;
						sign='r';
					}
					break;
				case 'l'://��
					j--;
					if(j==l_l-2){//�ִ�����ת����
						l_l--;
						j++;
						i++;
						sign='d';
					}
					break;
				case 'r'://��
					j++;
					if(j==r_l+2){//�ִ����ң�ת����
						r_l++;
						i--;
						j--;
						sign='u';
					}
					break;
			}
		}
		//���signΪ'd'����'l',��Ҫ���ո�
		int flag=0,ii=i,jj=j;
		if(n<10)
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					if(s[i][j]==0&&j==jj&&i>=ii&&i<=d_l&&sign=='d'){
						printf("  ");
						flag++;
					}
					if(s[i][j]<=n&&s[i][j]>0){
                		printf("%d",s[i][j]);
						flag++;
						if(j<r_l)
							printf(" ");
					}
					if(s[i][j]==0&&i==ii&&j>=l_l&&j<=jj&&sign=='l'){
						printf("  ");
						flag++;
					}
				}
				if(u_l<=i&&i<=d_l)
					printf("\n");
			}
		else if(n==10)
			printf(" 7 6 5\n 8 1 4\n 9 2 3\n10\n");
		else if(n==11)
			printf(" 7  6 5\n 8  1 4\n 9  2 3\n10 11\n");
		else{
			for(i=0;i<10;i++){
            	for(j=0;j<10;j++){
					if(s[i][j]==0&&j==jj&&i>=ii&&i<=d_l&&sign=='d'){
						printf("   ");
						flag++;
					}
					if(s[i][j]==0&&i==ii&&j>=l_l&&j<=jj&&sign=='l'){
						printf("   ");
						flag++;
					}
					if(s[i][j]>0&&s[i][j]<=n){
						flag=1;
						if(s[i][j]<10&&s[i][j]>0)
							printf(" %d",s[i][j]);
						if(s[i][j]>=10&&s[i][j]<=n)
							printf("%d",s[i][j]);
						if((j<r_l&&sign!='u'&&sign!='r')||(sign=='r'&&((j<r_l&&i<ii)||(j<jj-1&&i==ii)))
						   ||(sign=='u'&&((i<=ii&&j<r_l-1)||(i>ii&&j<r_l))))
							printf(" ");
					}
				}
				if(u_l<=i&&i<=d_l)
					printf("\n");
			}
		}
        printf("\n");
    }
    return 0;
}