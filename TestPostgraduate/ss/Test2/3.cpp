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
    ListNode* sortList(ListNode* head){
        //填充本函数完成功能
        ListNode *L = new ListNode;
        L->next = NULL;
        while(head){
        	ListNode *p = head->next;
        	if(L->next == NULL){
        		head->next = L->next;
        		L->next = head;
			}else{
				ListNode *q = L;
				while(q->next && q->next->val < head->val)
					q = q->next;
				head->next = q->next;
				q->next = head;
			}
			head = p;
		}
		head = L->next;
		return head;
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
    head=Solution().sortList(head);
    displayLink(head);
    return 0;
}
