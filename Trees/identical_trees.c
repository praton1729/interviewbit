
/*=========================================

* File Name 	: identical_trees.c

* Purpose 		: A func() to check if the two
				  given BTs are identical or not.

* Creation Date : 02-11-2018

* Last Modified : Friday 02 November 2018 02:46:27 PM IST

* Created By 	: Prathu Baronia, 14D070046 

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
 * @input B : Root pointer of the tree 
 * 
 * @Output Integer
 */

int isSameTree(treenode* A, treenode* B)
{
		if(A==NULL && B==NULL) return 1;
		if(A!=NULL && B!=NULL)
		{
				int a = (A->val==B->val) ? 1:0;
				int b = isSameTree(A->left,B->left);
				int c = isSameTree(A->right,B->right);
				if(a && b && c) return 1;
				else return 0;
		}
		return 0;
}


int main(int argc, char* argv)
{

		return 0;
}
