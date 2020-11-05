#include<stdio.h>
#include<string.h>
int isPal(char str[]);
int isMir(char str[]);
int main(){
	char str[20];
	while(scanf("%s",str)!=EOF){
		if(isPal(str)&&isMir(str))
			printf("%s -- is a mirrored palindrome.",str);
		else if(isPal(str)&&!isMir(str))
			printf("%s -- is a regular palindrome.",str);
		else if(!isPal(str)&&isMir(str))
			printf("%s -- is a mirrored string.",str);
		else
			printf("%s -- is not a palindrome.",str);
		printf("\n\n");
	}
	return 0;
}
int isPal(char str[]){
	int len=strlen(str),i;
	for(i=0;i<=(len+1)/2-1;i++)
		if(str[i]!=str[len-1-i])
			return 0;
	return 1;
}
int isMir(char str[]){
	int len=strlen(str),i,j,signal=-1;
	char sign[2][22]=
		{{'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8','0'}
		,{'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8','0'}};
	for(i=0;i<=(len+1)/2-1;i++){
		for(j=0;j<22;j++)
			if(str[i]==sign[0][j])
				signal=j;
		if(signal==-1)
			return 0;
		if((sign[1][signal]=='0'&&str[len-1-i]=='O')||(sign[1][signal]=='O'&&str[len-1-i]=='0'))
			continue;
		if(sign[1][signal]!=str[len-1-i])
			return 0;
	}
	return 1;
}