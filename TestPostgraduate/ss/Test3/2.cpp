#include<iostream>
using namespace std;
struct ListNode{
    char val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(char x) : val(x), next(NULL) {}
    ListNode(char x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int getDecimalValue(ListNode* head) {
		//填充本函数完成功能
		if(!head)
			return 0;
		int n;
		if(head->val >= '0' && head->val <= '9')
			n = head->val -'0';
		else
			n = head->val - 'A' + 10;
		n = n + 16 * getDecimalValue(head->next);
		return n;
    }
};
ListNode *createByTail(){
    ListNode *head;
    ListNode *p1,*p2;
    int n=0;
    char num;
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
int main(){
    ListNode* head = createByTail();
    int n;
    n=Solution().getDecimalValue(head);
    cout<<n<<endl;
    return 0;
}
