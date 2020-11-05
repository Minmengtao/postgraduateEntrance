#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //填充本函数完成功能
		ListNode *L, *p1, *p2;
		L = new ListNode();
		if(head == NULL || head->next == NULL)
			return head;
		ListNode *p = head, *q = head->next;
		while(q){
			if(p == head){//交换第一个结点
				 L->next = q;
				 p->next = q->next;
				 q->next = p;
			}else{
				p1->next = q;
				p->next = q->next;
				q->next = p;
			}
			p1 = p;
			p = p->next;
			if(p == NULL)
				break;
			q = p->next;
		} 
		return L->next;
    }
};
ListNode *createByTail(){
    ListNode *head;
    ListNode *p1,*p2;
    int n=0,num;
    int len;
    cin>>len;
    head=NULL;
    while(n<len && cin>>num){
        p1=new ListNode(num);
        n=n+1;
        if(n==1)
            head=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    return head;
}
void  displayLink(ListNode *head){
    ListNode *p;
    p=head;
    cout<<"head-->";
    while(p!= NULL){
        cout<<p->val<<"-->";
        p=p->next;
    }
    cout<<"tail\n";
}
int main(){
    ListNode* head = createByTail();
    head=Solution().swapPairs(head);
    displayLink(head);
    return 0;
}
