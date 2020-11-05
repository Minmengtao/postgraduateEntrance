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
