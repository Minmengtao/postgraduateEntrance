#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	char s[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	while(scanf("%s\n",str)!=EOF){
		int len=strlen(str);
		int i,j,k;
		for(i=0;i<len;i++)
			if(str[i]=='!')
				break;
		int count[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		for(j=0;j<i;j++){
			if(str[j]=='a'||str[j]=='A')
				count[0]++;
			if(str[j]=='b'||str[j]=='B')
				count[1]++;
			if(str[j]=='c'||str[j]=='C')
				count[2]++;
			if(str[j]=='d'||str[j]=='D')
				count[3]++;
			if(str[j]=='e'||str[j]=='E')
				count[4]++;
			if(str[j]=='f'||str[j]=='F')
				count[5]++;
			if(str[j]=='g'||str[j]=='G')
				count[6]++;
			if(str[j]=='h'||str[j]=='H')
				count[7]++;
			if(str[j]=='i'||str[j]=='I')
				count[8]++;
			if(str[j]=='j'||str[j]=='J')
				count[9]++;
			if(str[j]=='k'||str[j]=='K')
				count[10]++;
			if(str[j]=='l'||str[j]=='L')
				count[11]++;
			if(str[j]=='m'||str[j]=='M')
				count[12]++;
			if(str[j]=='n'||str[j]=='N')
				count[13]++;
			if(str[j]=='o'||str[j]=='O')
				count[14]++;
			if(str[j]=='p'||str[j]=='P')
				count[15]++;
			if(str[j]=='q'||str[j]=='Q')
				count[16]++;
			if(str[j]=='r'||str[j]=='R')
				count[17]++;
			if(str[j]=='s'||str[j]=='S')
				count[18]++;
			if(str[j]=='t'||str[j]=='T')
				count[19]++;
			if(str[j]=='u'||str[j]=='U')
				count[20]++;
			if(str[j]=='v'||str[j]=='V')
				count[21]++;
			if(str[j]=='w'||str[j]=='W')
				count[22]++;
			if(str[j]=='x'||str[j]=='X')
				count[23]++;
			if(str[j]=='y'||str[j]=='Y')
				count[24]++;
			if(str[j]=='z'||str[j]=='Z')
				count[25]++;
		}
		for(k=0;k<26;k++){
			if(count[k]!=0)
				printf("%c:%d\n",s[k],count[k]);
		}
	}
	return 0;
}