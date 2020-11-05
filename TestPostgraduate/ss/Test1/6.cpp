#include <iostream>
using namespace std;

typedef struct ListNode{
	int id;
	struct ListNode *next;
}ListNode;
//采用前插法创建链表(带头结点) 
ListNode *create(){
    ListNode *head;
    ListNode *p1,*p2;
    int n, num;
    cin >> n;
    head = new ListNode;
	head->next = NULL;  //首先置链表为空链表
	p2 = head;
    for(int i = 0; i < n; i++){
    	cin >> num;
    	p1 = new ListNode;
    	p1->id = num;
    	p2->next = p1;
    	p2 = p1;//p2始终指向最后一个结点（即尾指针）
	}
    p2->next=NULL;  //切记：最后一个结点的next赋值为NULL
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
