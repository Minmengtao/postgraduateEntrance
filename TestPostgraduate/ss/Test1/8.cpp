#include <iostream>
using namespace std;

typedef struct ListNode{
	int id;
	struct ListNode *next;
}ListNode;

//����ǰ�巨��������(��ͷ���) 
ListNode *create(int n){
    ListNode *head;
    ListNode *p1,*p2;
    head = new ListNode;
	head->next = NULL;  //����������Ϊ������
	p2 = head;
    for(int i = 1; i <= 2 * n; i++){
    	p1 = new ListNode;
    	p1->id = i;
    	p2->next = p1;
    	p2 = p1;//p2ʼ��ָ�����һ����㣨��βָ�룩
	}
    p2->next = head->next;  //��β���ָ��ָ��ͷ����next��㣬�γ�ѭ������ 
    return head;
}

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    ListNode *head = create(n);
    ListNode *p = head->next;
	for(int i = 1; i <= n; i++){//����ɾ��ͷ������ 
		int j = 1;
		while(j != m - 1){//ÿ��������m-1�����
			//cout << p->id << " ";
			p = p->next;
			j++;
		}
		//cout << p->id << " ";
		//ɾ����m�����	q
		ListNode *q = p->next;
		if(head->next->id == q->id)//�ж�ɾ������Ƿ�Ϊͷ��� 
			head->next = q->next;
		p->next = q->next;
		p = p->next;
		delete q;
	}
	p = head->next; 
	for(int i = 1; i <= 2*n; i++){
		int num = p->id;
		if(num == i){
			p = p->next;
			cout << "G";
		}else{
			cout << "B";
		}
		if(i % 50 == 0)
			cout << endl;
	}
    return 0;
}
