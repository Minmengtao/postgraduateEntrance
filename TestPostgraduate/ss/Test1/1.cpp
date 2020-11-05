#include <iostream>
using namespace std;

typedef struct ListNode{
	int id;
	struct ListNode *next;
}ListNode;
//采用前插法创建链表(不带头结点) 
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

int getIndex(ListNode *p, int num){//锁定num在链表的位置 
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
