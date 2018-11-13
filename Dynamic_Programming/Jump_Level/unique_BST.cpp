
//Definition for binary tree

struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* TreeNode_new(int x)
{
		TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
		node->left = NULL;
		node->right = NULL;
		node->val = x;
		return node;
}

vector<TreeNode*> generateTrees_util(int start,int end)
{
		vector<TreeNode*> list;

		if(start>end)
		{
				list.push_back(NULL);
				return list;
		}

		for(int i=start;i<=end;i++)
		{
				vector<TreeNode*> left_subtree = generateTrees_util(start,i-1);
				vector<TreeNode*> right_subtree = generateTrees_util(i+1,end);

				for(int j=0;j<left_subtree.size();j++)
				{
						TreeNode* left = left_subtree[j];
						for(int k=0;k<right_subtree.size();k++)
						{
								TreeNode* right = right_subtree[k];
								TreeNode* node = TreeNode_new(i);
								node->left = left;
								node->right = right;
								list.push_back(node);
						}
				}
		}
}

vector<TreeNode*> Solution::generateTrees(int A) {

		return generateTrees_util(1,A);
}

