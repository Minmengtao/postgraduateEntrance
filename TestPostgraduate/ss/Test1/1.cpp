#include <iostream>
using namespace std;

typedef struct ListNode{
	int id;
	struct ListNode *next;
}ListNode;
//����ǰ�巨��������(����ͷ���) 
ListNode *create(){
    ListNode *head;
    ListNode *p1,*p2;
    int n, num;
    cin >> n;
    head = new ListNode;
	head->next = NULL;  //����������Ϊ������
	p2 = head;
    for(int i = 0; i < n; i++){
    	cin >> num;
    	p1 = new ListNode;
    	p1->id = num;
    	p2->next = p1;
    	p2 = p1;//p2ʼ��ָ�����һ����㣨��βָ�룩
	}
    p2->next=NULL;  //�мǣ����һ������next��ֵΪNULL
    return head;
}

int getIndex(ListNode *p, int num){//����num�������λ�� 
	int i = 1;
	p = p->next;
	while(p!=NULL){
		if(p->id == num)
			break; 
		i++;
		p = p->next;
	}
	if(p!=NULL)
		return i;
	else
		return -1;
}

int main(){
    int num;
    ListNode* head = create();
	while(cin >> num){
		int index = getIndex(head,num);
		if(index > 0)
    		cout << index << endl;
    	else
    		cout << "no" << endl;
    }
    return 0;
}
