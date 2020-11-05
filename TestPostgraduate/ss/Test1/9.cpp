#include <iostream>
#include <cstring>
using namespace std;

struct List{
	int sig;//������0��1��������-1
	int num;
	struct List *prior, *next;
};
int lenA = 0, lenB = 0; 
void display(List *L, int x){//��ӡ���� 
	if(L->sig < 0 && x)
		cout << "-";
	List *p = L->next;
	while(p){
		if(L->next != p){//������һ����㣬�Բ�����λ���Ĳ��� 
			if(p->num>=0&&p->num<10)
				cout << "000";
			if(p->num>=10 && p->num<100)
				cout << "00";
			if(p->num>=100 && p->num<1000)
				cout << "0"; 
		}
		cout << p->num;
		if(p->next){
			if(x)
				cout << ",";
			else
				cout << "->";
		}
		p = p->next;
	}
	cout << endl;
}
List *create(char *s, int &len){//��ͷ����˫��ѭ������ ,β�巨 
	List *L, *p;
	L = new List;
	L->next = NULL;
	L->prior = NULL;
	p = L->next;
	int low;
	if(s[0] == '-'){
		L->sig = -1;
		low = 1;
	}else{
		L->sig = 1;
		low = 0;
	}
	//ȥ��000001ǰ����0
	while(s[low] == '0' && low < strlen(s)-1)
		low++; 
	for(int i = strlen(s)-1; i >= low; i = i-4){
		len++;
		int num = (s[i]-'0');
		if(i-1>=low)  
			num += (s[i-1]-'0')*10;
		if(i-2>=low)
			num += (s[i-2]-'0')*100;
		if(i-3>=low)
			num += (s[i-3]-'0')*1000;
		List *q = new List;
		q->num = num;
		//��һ��������
		if(i == strlen(s)-1){//β�巨�����һ����� 
			q->next = L->next;
			L->next = q;
			q->prior = L;
			L->prior = q;//����һ��ѭ��˫���� 
		}else{
			q->next = L->next;
			L->next->prior = q;
			L->next = q;
			q->prior = L;
		}
	}
	return L;
}
List *calculate(List *La, List *Lb){//La��Lb�� 
	List *Lc, *p = La->prior, *q = Lb->prior;
	int sign = 0;
	Lc = new List;
	Lc->next = NULL;Lc->prior = NULL; 
	while(p!=La){//����������� 
		int num = 0, numb = 0;
		if(q!=Lb)
			numb = q->num;
		if(La->sig + Lb->sig != 0){//������Ϊ�������� 
			num += p->num + numb + sign;
			sign = num / 10000;
		}else{//һ��һ�� 
			if(p->num + sign >= numb){
				num += p->num - numb + sign;
				sign = num / 10000;
			}else{
				num += p->num - numb + sign + 10000;
				sign = -1;
			}
		}
		p->num = num % 10000;
		p = p->prior;
		if(q!=Lb)
			q = q->prior;
	}
	//cout << 1 << endl;
	if(sign != 0){//�ж������Ƿ�������� 
		List *p1;
		p1 = new List;
		p1->num = sign;
		p1->next = La->next;
		La->next->prior = p1;
		La->next = p1;
		p1->prior = La;
	}
	//cout << 2 << endl;
	p = La->next;
	while(p->num == 0 && p->next)
		p = p->next;
	//cout << 3 << endl;
	Lc->next = p;
	if(p->num == 0 && p->next == NULL)//������Ϊ�෴��ʱ 
		Lc->sig = 1;
	else
		Lc->sig = La->sig;
	return Lc;
}
int main(){
	char s1[10005], s2[10005];
	cin >> s1 >> s2;
	List *La, *Lb, *Lc;
	La = create(s1, lenA);
	Lb = create(s2, lenB);
	display(La, 1);
	display(Lb, 1);
	cout << endl;
	if(lenA > lenB || (La->next->num > Lb->next->num && lenA == lenB))
		Lc = calculate(La, Lb);
	else
		Lc = calculate(Lb, La);
	display(Lc, 0);
	display(Lc, 1);
	return 0;
}
