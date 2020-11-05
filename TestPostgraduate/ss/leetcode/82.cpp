#include <iostream>
#include <vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head || !head->next)
    		return head;
        ListNode *p = head, *q = head->next, *r;
        while(q){
        	if(p->val == q->val){
        		r = q;
        		q = r->next;
        		delete r;
        		p->next = q;
			}else{
				q = q->next;
				p = p->next;
			}
		}
		return head;
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
	ListNode *head = createByTail();
    displayLink(Solution().deleteDuplicates(head));
    return 0;
}
