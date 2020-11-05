#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
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
	int maxSum;
	int maxPathSum(TreeNode *root){
		maxSum = INT_MIN;
		dfs(root);
		return maxSum;
	}
	int dfs(TreeNode *root){
		if(root == NULL)
			return 0;
		int lMax = max(0, dfs(root->left));//记录左子树最大值 
		int rMax = max(0, dfs(root->right));//记录右子树最大值 
		maxSum = max(maxSum, root->val + lMax + rMax);//记录左子树+右子树+根节点数值与原记录最大值中取最大值 
		return root->val + max(lMax, rMax);//返回单一分支的最大值 
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
    int res=Solution().maxPathSum(root);
    cout<<res<<endl;
}
