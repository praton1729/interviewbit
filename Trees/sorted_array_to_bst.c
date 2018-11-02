
/*=========================================

* File Name		:	sorted_array_to_bst.c

* Purpose		:	A func() that converts a
					sorted array to a balanced
					BST.

* Creation Date	:	02-11-2018

* Last Modified	:	Mon 22 Dec 2008 10:36:49 PM PST

* Created By	: 	Prathu Baronia, 14D070046 

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
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output root pointer of tree.
 */

treenode* sorted_array_to_bst_util(const int* A, int start, int end)
{
		if(start>end) return NULL;
		int mid = (start+end)/2;
		treenode* root = treenode_new(A[mid]);

		root->left = sorted_array_to_bst_util(A,start,mid-1);
		root->right = sorted_array_to_bst_util(A,mid+1,end);

		return root;
}
treenode* sortedArrayToBST(const int* A, int n1) {

		treenode* root = (treenode*) malloc(sizeof(treenode));
		root = sorted_array_to_bst_util(A,0,n1-1);

		return root;
}


int main(int argc, char* argv)
{

		return 0;
}
