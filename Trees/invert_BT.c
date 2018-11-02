
/*=========================================

* File Name 	: invert_BT.c

* Purpose 		: A func() to invert a given BT

* Creation Date : 02-11-2018

* Last Modified : Friday 02 November 2018 02:59:14 PM IST

* Created By 	: Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>


//Definition for binary tree

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
 * @Output root pointer of tree.
 */

treenode* invertTree(treenode* A) {
		if(A==NULL) return NULL;

		treenode* temp = invertTree(A->left);
		A->left = invertTree(A->right);
		A->right = temp;

		return A;
}


int main(int argc, char* argv)
{

		return 0;
}
