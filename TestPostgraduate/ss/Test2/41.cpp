#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(!root)
    		return true;
    	bool b = judge(root->left, root->right);
    	return b;
    }
    bool judge(TreeNode* l, TreeNode* r){
    	if(l == NULL && r == NULL)
    		return true;
    	else if(l == NULL || r == NULL)
    		return false;
    	else if(l->val == r->val)
    		return judge(l->left, r->right) && judge(l->right, r->left);
		else
			return false; 
	}
};

TreeNode* inputTree(){
    int n,count=0;
    char item[100];
    cin>>n;
    if (n==0)
        return NULL;
    cin>>item;
    TreeNode* root = new TreeNode(atoi(item));
    count++;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (count<n){
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0){
            int leftNumber = atoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (count==n)
            break;
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0){
            int rightNumber = atoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main(){ 
	TreeNode* root;
	root=inputTree();
	bool res=Solution().isSymmetric(root);
	cout<<(res?"true":"false");
	return 0; 
}
