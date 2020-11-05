#include <iostream>
using namespace std;

typedef struct ListNode{
	int id;
	struct ListNode *next;
}ListNode;

//采用前插法创建链表(带头结点) 
ListNode *create(int n){
    ListNode *head;
    ListNode *p1,*p2;
    head = new ListNode;
	head->next = NULL;  //首先置链表为空链表
	p2 = head;
    for(int i = 1; i <= 2 * n; i++){
    	p1 = new ListNode;
    	p1->id = i;
    	p2->next = p1;
    	p2 = p1;//p2始终指向最后一个结点（即尾指针）
	}
    p2->next = head->next;  //将尾结点指针指向头结点的next结点，形成循环链表 
    return head;
}

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    ListNode *head = create(n);
    ListNode *p = head->next;
	for(int i = 1; i <= n; i++){//出现删除头结点情况 
		int j = 1;
		while(j != m - 1){//每遍历到第m-1个结点
			//cout << p->id << " ";
			p = p->next;
			j++;
		}
		//cout << p->id << " ";
		//删除第m个结点	q
		ListNode *q = p->next;
		if(head->next->id == q->id)//判断删除结点是否为头结点 
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
