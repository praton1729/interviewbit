
/*=========================================

* File Name		:	min_depth_BT.c

* Purpose		:	A func() that returns min number 
					of nodes from root to a lead node.

* Creation Date	:	02-11-2018

* Last Modified	:	Friday 02 November 2018 08:09:45 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>


// Definition for binary tree

struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
};

typedef struct TreeNode treenode;

treenode* treenode_new(int val) {
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

int min(int a, int b)
{
		return ((a)>(b)) ? (b):(a);
}

int minDepth(treenode* A) 
{
		if(A == NULL) return 0;

		if(A->left == NULL && A->right == NULL) return 1;

		if(A->left == NULL) return (minDepth(A->right)+1);
		if(A->right == NULL) return (minDepth(A->left)+1);

		return (min(minDepth(A->left),minDepth(A->right))+1);
}



int main(int argc, char* argv)
{

		return 0;
}
