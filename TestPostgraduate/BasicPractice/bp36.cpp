#include<stdio.h>
int main(){
	int m;
	while(scanf("%d\n",&m)!=EOF){
		char d;
		double g,price[4]={1.5,1.4,1.48,1.08},sum_price=0.0,sum_weight=0.0;
		double a_weight=0.0,o_weight=0.0,b_weight=0.0,p_weight=0.0;
		double a_price=0.0,o_price=0.0,b_price=0.0,p_price=0.0;
		int i=0;
		while(i<m){
			scanf("%c %lf\n",&d,&g);
			if(d=='a'){
				a_weight+=g;
				a_price+=price[0]*g;
			}
			if(d=='o'){
				o_weight+=g;
				o_price+=price[1]*g;
			}
			if(d=='b'){
				b_weight+=g;
				b_price+=price[2]*g;
			}
			if(d=='p'){
				p_weight+=g;
				p_price+=price[3]*g;
			}
			i++;
		}
		sum_weight=a_weight+o_weight+b_weight+p_weight;
		sum_price=a_price+o_price+b_price+p_price;
		printf("       apple  orange banana pineapple sum\n");
		printf("price  %-7.2f%-7.2f%-7.2f%-10.2f%-7.2f\n",a_price,o_price,b_price,p_price,sum_price);
		printf("weight %-7.2f%-7.2f%-7.2f%-10.2f%-7.2f\n",a_weight,o_weight,b_weight,p_weight,sum_weight);
		printf("\n");
	}
	return 0;
}