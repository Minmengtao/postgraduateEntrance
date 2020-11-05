#include <iostream>
#include <queue>
#include <stack>
#include<cstdlib>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
	int sum = 0;
	int maxSumBST(TreeNode *root){
		if(!root)
			return 0;
		dfs(root);
		return sum;
	}
	int dfs(TreeNode *root){
		bool left = false, right = false;
		int x1 = 0, x2 = 0;
		if(root->left){
			x1 = dfs(root->left);
			if(x1 != INT_MIN && root->left->val < root->val)
				left = true;
		}else
			left = true;
		if(root->right){
			x2 = dfs(root->right);
			if(x2 != INT_MIN && root->right->val > root->val)
				right = true;
		}else
			right = true;
		if(left && right){
			int x = x1 + x2 + root->val;
			if(x >= sum)
				sum = x;
			return x;
		}else
			return INT_MIN;
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
    int res=Solution().maxSumBST(root);
    cout<<res;
}
