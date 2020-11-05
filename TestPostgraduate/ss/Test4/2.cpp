#include <iostream>
#include <queue>
#include <stack> 
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
	double aveDepth(TreeNode *root){
		int maxL = maxLevel(root);
		int minL = minLevel(root);
		double ct = (maxL + minL) / 2;
		cout << maxL << " " << minL << endl;
		return ct;
	}
	int minLevel(TreeNode *root){
		if(!root)
			return 0;
		int left = minLevel(root->left);
		int right = minLevel(root->right);
		if(!root->left || !root->right)
			return left + right + 1;
		return 1 + min(left, right);
	}
	int maxLevel(TreeNode *root){
		if(!root)
			return 0;
		return max(maxLevel(root->left), maxLevel(root->right)) + 1;
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
    while (count<n)
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0)
        {
            int leftNumber = atoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (count==n)
            break;
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0)
        {
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
    double res=Solution().aveDepth(root);
    cout<<res;
} 
