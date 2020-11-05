#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode;
        ListNode *p = head;
        while(l1 && l2){
        	if(l1->val <= l2->val){
        		p->next = l1;
        		l1 = l1->next;
			}else{
        		p->next = l2;
        		l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2;
		return head->next;
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
    ListNode* l1 = createByTail();
    ListNode* l2 = createByTail();
    displayLink(Solution().mergeTwoLists(l1, l2));
    return 0;
}
