#include <iostream>
using namespace std;

struct  Node{
    int coef;///系数
    int  expn;///指数
    struct Node *next;
};//输入链表指数数值递增有序 
Node *create(){
	int n;
	cin >> n;
	Node *L, *p, *q;
	L = new Node;
	L->next = NULL;
	p = L;
	while(n--){
		q = new Node;
		cin >> q->coef;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	p = L->next;
	while(p){
		cin >> p->expn;
		p = p->next;
	} 
	return L;
}
void display(Node *L){
	Node *p = L->next;
	if(!p || (p->coef==0 && p->expn==0)){
		cout << "0 0" << endl << endl;
		return ;
	}
	while(p){
		cout << p->coef << " " << p->expn << endl;
		p = p->next;
	}
	cout << endl;
}
void alert(Node *L){
	Node *p = L->next;
	while(p){
		p->coef = p->coef * (-1);
		p = p->next;
	}
}
void reverse(Node *L){
	Node *p = L->next;
	L->next = NULL;
	while(p){
		Node *q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
Node *add(Node *La, Node *Lb){//默认使用加法运算 
	Node *p = La->next, *q = Lb->next, *L;
	L = new Node;
	L->next = NULL;
	while(p && q){
		Node *p1;
		if(p->expn > q->expn){
			p1 = q->next;
			q->next = L->next;
			L->next = q;
			q = p1;
		}else if(p->expn < q->expn){
			p1 = p->next;
			p->next = L->next;
			L->next = p;
			p = p1;
		}else{
			p->coef = p->coef + q->coef;
			if(p->coef != 0){
				p1 = p->next;
				p->next = L->next;
				L->next = p;
				p = p1;
			}else
				p = p->next;
			q = q->next;
		}
	} 
	while(p){
		Node *p1 = p->next;
		p->next = L->next;
		L->next = p;
		p = p1;
	}
	while(q){
		Node *p1 = q->next;
		q->next = L->next;
		L->next = q;
		q = p1;
	}
	reverse(L);
	return L;
}

int main(){
	int ad;
	cin >> ad;
	Node *La, *Lb;
	La = create();
	display(La);
	Lb = create();
	display(Lb);
	if(ad == 1)//减法运算让Lb系数自乘-1 
		alert(Lb);
	La = add(La, Lb);
	display(La);
	return 0;
}
