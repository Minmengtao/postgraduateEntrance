#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> vec;
		if(root == NULL)
            return vec;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
        	int size = q.size();
        	vector<int> v;
        	for(int i = 0; i < size; i++){
        		TreeNode *p = q.front();
        		v.push_back(p->val);
        		q.pop();
        		if(p->left)
        			q.push(p->left);
        		if(p->right)
        			q.push(p->right);
			}
			vec.push_back(v);
		}
		return vec;
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
    vector<vector<int>> vec = Solution().levelOrder(root);
    for(int i = 0; i < vec.size(); i++){
    	for(int j = 0; j<vec[i].size(); j++){
    		cout << vec[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
