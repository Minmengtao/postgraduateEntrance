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
void  displayLink(ListNode *a, ListNode *b){
	ListNode *p1 = a->next, *p2 = b->next;
	printf("head-->");
	while(p1 != NULL && p2 != NULL){
		if(p1->id > p2->id)
			p2 = p2->next;
		else if(p1->id < p2->id)
			p1 = p1->next;
		else{
			printf("%d-->", p1->id);
			p1 = p1->next;
			p2 = p2->next;
		}
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
