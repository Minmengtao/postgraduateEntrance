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
	ListNode* mergeKLists(vector<ListNode*>& lists) {//分治算法 
		return merge(lists, 0, lists.size() - 1);
    }
    ListNode *merge(vector<ListNode *> &lists, int l, int r){
    	if(l == r)
    		return lists[l];
    	if(l > r)
    		return NULL;
    	int mid = (l + r) / 2;
    	ListNode *left = merge(lists, l, mid);//分割左半边
		ListNode *right = merge(lists, mid + 1, r);//分割右半边
		return mergeTwoLists(left, right); 
	} 
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
	vector<ListNode *> lists;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ListNode *list = createByTail();
		lists.push_back(list);
	}
    displayLink(Solution().mergeKLists(lists));
    return 0;
}
