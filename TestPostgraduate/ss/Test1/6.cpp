#include <iostream>
using namespace std;

typedef struct ListNode{
	int id;
	struct ListNode *next;
}ListNode;
//����ǰ�巨��������(��ͷ���) 
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
void printList(ListNode *head){
	ListNode *p = head->next;
	while(p){
		cout << p->id << " ";
		p = p->next;
	}
	cout << endl;
}
int judge(ListNode *b, int num){
	ListNode *p = b->next;
	while(p!=NULL){
		if(p->id == num)
			return 1;
		p = p->next;
	}
	return 0;
}
void  displayLink(ListNode *a, ListNode *b){
	ListNode *p = a->next;
	printf("head-->");
	while(p!= NULL){
		if(judge(b, p->id))
			printf("%d-->", p->id);
		p = p->next;
	}
	printf("tail\n");
}
int main(){
    int num;
    ListNode *a = create();
    ListNode *b = create();
    displayLink(a, b);
    return 0;
}
