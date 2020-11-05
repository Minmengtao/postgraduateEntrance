#include<iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        //完成本函数
        ListNode *p = head, *q = head;
        if(head == NULL)
        	return NULL;
        int len = 0;
        while(p){
        	len++;
        	p = p->next;
		}
		k = k % len;
		if(k == 0)
			return head;
		p = head;
        for(int i = 1; i <= k; i++)
			p = p->next;
		while(p->next){
			p = p->next;
			q = q->next;
		}
		ListNode *L = q->next;
		q->next = NULL;
		p->next = head;
		return L;
    }
};
ListNode *createByTail(){//不带头结点 
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
    int k;
    ListNode* head = createByTail();
    cin>>k;
    head=Solution().rotateRight(head,k);
    displayLink(head);
    return 0;
}
