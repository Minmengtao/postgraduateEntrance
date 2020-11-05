#include<iostream>
#include<vector>
#include<set> 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ans = 0;
		ListNode* newList = new ListNode;
		while(l1!=NULL&&l2!=NULL){
			ans = ans + l1->val + l2->val;
			ListNode* node = new ListNode;
			if(ans<9){
				node->val = ans;
				ans = 0;
			}else{
            	node->val = ans%10;
            	ans %= 10;
        	}
        	node->next = newList;
        	newList->next = node;
        	newList = newList->next;
        	l1 = l1->next;
        	l2 = l2->next;
    	}
    	return newList;
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
void displayLink(ListNode *head){
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
    ListNode* l1 = createByTail(), *l2 = createByTail();
    displayLink(Solution().addTwoNumbers())
    return 0;
}
