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
		int lMax = max(0, dfs(root->left));//��¼���������ֵ 
		int rMax = max(0, dfs(root->right));//��¼���������ֵ 
		maxSum = max(maxSum, root->val + lMax + rMax);//��¼������+������+���ڵ���ֵ��ԭ��¼���ֵ��ȡ���ֵ 
		return root->val + max(lMax, rMax);//���ص�һ��֧�����ֵ 
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
