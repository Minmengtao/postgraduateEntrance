#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
	public:
		void reorderList(ListNode* head){
            //填充本函数完成功能
            ListNode *fast = head, *slow = head;
            if(head == NULL)
            	return;
			while(fast->next){//通过快慢指针找到链表中间结点 
				fast = fast->next;
				if(fast->next)
					fast = fast->next;
				else
					break;
				slow = slow->next;
				
			}//链表中间结点为slow 
			ListNode *re = slow->next;//从该结点开始后逆置
			slow->next = NULL;
			re = reverse(re);
			ListNode *a = head;
			while(re){
				ListNode *p = re->next, *q = a->next;
				re->next = a->next;
				a->next = re;
				re = p;
				a = q;
			}
    	}
    	ListNode *reverse(ListNode *L){
    		ListNode *p, *q;
    		q = L;
			p = NULL;
			while(q){
				L = L->next;
				q->next = p;
				p = q;
				q = L;
			}
			L = p;
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
    ListNode* head = createByTail();
    Solution().reorderList(head);
    displayLink(head);
    return 0;
}
