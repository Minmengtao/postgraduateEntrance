#include<stdio.h>
#include<stdlib.h>
typedef struct Cargo{
	int c;//���
	int k;//����
	int price;//�۸�
}Cargo;
typedef struct Discount{
	Cargo *cargo;
	int n;
	int p;//�Żݼ۸�
	int pri;//ԭ��
}Discount;
int order(Discount *dis,int s);
int main(){
	Discount *dis;
	Cargo *cargo;
	int s,i,j,b,min=0,k;
	scanf("%d",&s);
	dis=(Discount*)malloc(sizeof(Discount)*s);
	for(i=0;i<s;i++){
		scanf("%d",&dis[i].n);
		dis[i].cargo=(Cargo*)malloc(sizeof(Cargo)*dis[i].n);
		for(j=0;j<dis[i].n;j++)
			scanf("%d %d",&dis[i].cargo[j].c,&dis[i].cargo[j].k);
		scanf("%d",&dis[i].p);
	}
	scanf("%d",&b);
	cargo=(Cargo*)malloc(sizeof(Cargo)*b);
	for(i=0;i<b;i++){
		scanf("%d %d %d",&cargo[i].c,&cargo[i].k,&cargo[i].price);
		//min+=cargo[i].k*cargo[i].price;
	}
	for(i=0;i<s;i++){//����ԭ�۸�
		int price=0;
		for(j=0;j<dis[i].n;j++)
			for(k=0;k<b;k++){
				if(cargo[k].c==dis[i].cargo[j].c)
					price+=dis[i].cargo[j].k*cargo[k].price;
			}
		dis[i].pri=price;
	}
	order(dis,s);//�������Żݼ۸��ԭ�۸�֮������֮��ߵ�����
	for(i=0;i<s;i++){//�ȶԼ۸��������ʹ���Ż�
		int flag=0;
		for(j=0;j<dis[i].n;j++){
			for(k=0;k<b;k++){
				if(dis[i].cargo[j].c==cargo[k].c&&dis[i].cargo[j].k<=cargo[k].k)
					flag++;
			}
		}
		while(flag==dis[i].n){
			min+=dis[i].p;
			flag=0;
			for(j=0;j<dis[i].n;j++)
				for(k=0;k<b;k++)
					if(dis[i].cargo[j].c==cargo[k].c){
						cargo[k].k=cargo[k].k-dis[i].cargo[j].k;
						if(dis[i].cargo[j].k<=cargo[k].k)
							flag++;
					}
		}
	}
	for(k=0;k<b;k++)//��ʣ��һЩ�����޷������Żݣ�ֻ�ܵ�������
		if(cargo[k].k!=0)
			min+=cargo[k].k*cargo[k].price;
	printf("%d\n",min);
	return 0;
}
int order(Discount *dis,int s){
	int i,j;
	for(i=0;i<s;i++)
		for(j=i;j<s;j++)
			if(dis[i].pri-dis[i].p<dis[j].pri-dis[j].p){
				Discount temp=dis[i];
				dis[i]=dis[j];
				dis[j]=temp;
			}
	return 1;
}