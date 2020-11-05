#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left, *right, *p, *q, *prior;
        left = new ListNode(0);
        right = new ListNode(0);
        p = left; q = right;
        while(head){
        	prior = head->next;
        	if(head->val < x){
        		head->next = p->next;
        		p->next = head;
        		p = head;
			}else{
				head->next = q->next;
        		q->next = head;
        		q = head;
			}
        	head = prior;
		}
		p->next = right->next;
		return left->next;
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
    int k;
    ListNode* head = createByTail();
    cin>>k;
    head=Solution().partition(head,k);
    displayLink(head);
    return 0;
}
