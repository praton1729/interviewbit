
/*=========================================

* File Name		:	max_path_sum_BT.c

* Purpose		:	A func() that returns the max
					sum in a path across a BT where
					the path can start on any node 
					and end on any node.

* Creation Date	:	16-11-2018

* Last Modified	:	Friday 16 November 2018 08:11:43 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

// Definition for binary tree

struct TreeNode
{
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
};

typedef struct TreeNode treenode;

treenode* treenode_new(int val)
{
		treenode* node = (treenode *) malloc(sizeof(treenode));
		node->val = val;
		node->left = NULL;
		node->right = NULL;
		return node;
}


/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */

int max(int a, int b)
{
		return ((a)>(b))?(a):(b);
}

int maxPathSum_util(treenode* root, int* result)
{
		if(root==NULL) return 0;

		int l = maxPathSum_util(root->left,result);
		int r = maxPathSum_util(root->right,result);

		int max_single = max(max(l,r)+root->val,root->val);

		int max_top = max(max_single, l + r + root->val);

		*result = max(*result,max_top);

		return max_single;
}

int maxPathSum(treenode* A) {
		int res = INT_MIN;
		int* res_pointer;
		res_pointer = &res;

		maxPathSum_util(A,res_pointer);
		return res;
}


int main(int argc, char* argv)
{

		return 0;
}
