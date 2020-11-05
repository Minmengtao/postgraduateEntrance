#include<stdio.h>
typedef struct Card{
	char color;
	char size;
}Card;
typedef struct Poker{
	Card card[13];
}Poker;
int getIndex(char x);
int main(){
	Poker poker[4];
	int n;
	scanf("%d",&n);
	while(n--){
		int i;
		for(i=0;i<4;i++){
			int j;
			for(j=0;j<13;j++){
			    char s=getchar();
				if(s==" ")
					continue;
				else{
					scanf("%c",&poker[i].card[j].color);//=getchar();
					scanf("%c",&poker[i].card[j].size);//=getchar();
				}
		    }
			int k;
			for(j=0;j<13;j++)
				for(k=j;k<13;k++)
					if((getIndex(poker[i].card[j].size)>getIndex(poker[i].card[k].size))||(poker[i].card[j].size==poker[i].card[k].size
						&&poker[i].card[j].color<poker[i].card[k].color)){
						Card temp=poker[i].card[j];
						poker[i].card[j]=poker[i].card[k];
						poker[i].card[k]=temp;
					}
			for(j=0;j<12;j++)
				printf("%c%c ",poker[i].card[j].color,poker[i].card[j].size);
			printf("%c%c\n",poker[i].card[j].color,poker[i].card[j].size);
		}
		printf("\n");
	}
	return 0;
}
int getIndex(char x){
	char size[13]={'A','K','Q','J','T','9','8','7','6','5','4','3','2'};
	int i;
	for(i=0;i<13;i++)
		if(x==size[i])
			return i;
	return -1;
}