#include<stdio.h>
int isSpecial(char str[],int);
int main(){
	int i,B,j,divi,temp;
	scanf("%d\n",&B);
	char str[12];
	for(i=1;i<=300;i++){
		j=0;
		divi=i*i;
		int k=0;
		while(divi!=0){
			temp=divi%B;
			switch(temp){
				case 0:str[j]='0';break;
				case 1:str[j]='1';break;
				case 2:str[j]='2';break;
				case 3:str[j]='3';break;
				case 4:str[j]='4';break;
				case 5:str[j]='5';break;
				case 6:str[j]='6';break;
				case 7:str[j]='7';break;
				case 8:str[j]='8';break;
				case 9:str[j]='9';break;
				case 10:str[j]='A';break;
				case 11:str[j]='B';break;
				case 12:str[j]='C';break;
				case 13:str[j]='D';break;
				case 14:str[j]='E';break;
				case 15:str[j]='F';break;
				case 16:str[j]='G';break;
				case 17:str[j]='H';break;
				case 18:str[j]='I';break;
				case 19:str[j]='J';break;
				case 20:str[j]='K';break;
			}
			j++;
			divi=divi/B;
			k++;
		}
		if(isSpecial(str,k)==1){
			int div=i;
			j=0;
			int m=0;
			char strg[10];
			while(div!=0){
				temp=div%B;
				switch(temp){
					case 0:strg[j]='0';break;
					case 1:strg[j]='1';break;
					case 2:strg[j]='2';break;
					case 3:strg[j]='3';break;
					case 4:strg[j]='4';break;
					case 5:strg[j]='5';break;
					case 6:strg[j]='6';break;
					case 7:strg[j]='7';break;
					case 8:strg[j]='8';break;
					case 9:strg[j]='9';break;
					case 10:strg[j]='A';break;
					case 11:strg[j]='B';break;
					case 12:strg[j]='C';break;
					case 13:strg[j]='D';break;
					case 14:strg[j]='E';break;
					case 15:strg[j]='F';break;
					case 16:strg[j]='G';break;
					case 17:strg[j]='H';break;
					case 18:strg[j]='I';break;
					case 19:strg[j]='J';break;
					case 20:strg[j]='K';break;
				}
				j++;
				div=div/B;
				m++;
			}
			while(m--)
				printf("%c",strg[m]);
			printf(" ");
			while(k--)
				printf("%c",str[k]);
			printf("\n");
		}
		
	}
	return 0;
}
int isSpecial(char str[],int len){
	int i=0;
	while(i<=(len-1)/2){
		if(str[i]!=str[len-i-1])
			return 0;
		i++;
	}
	return 1;
}