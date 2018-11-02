
/*=========================================

* File Name			:	kth_smallest_element_BST.c

* Purpose			:	A func() that returns kth smallest
						element in a BST.

* Creation Date		:	02-11-2018

* Last Modified		:	Friday 02 November 2018 08:46:34 PM IST

* Created By		: 	Prathu Baronia, 14D070046 

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
 * @input B : Integer
 * 
 * @Output Integer
 */

#define MAX_NUMBER_OF_NODES 100000

int kthsmallest(treenode* A, int B) {

		if(A==NULL) return INT_MIN;

		int* result = (int*) malloc(MAX_NUMBER_OF_NODES*sizeof(int));
		treenode** stack = (treenode**) malloc(MAX_NUMBER_OF_NODES*sizeof(treenode*));
		int top = -1,count=-1;
		int done = 0;
		treenode* current_node = A;

		/*
		 * Populating result with node data in an iterative fashion
		 * and updating count as we go around the tree.
		 */

		while(!done)
		{
				if(current_node!=NULL)
				{
						stack[++top] = current_node;    
						current_node = current_node->left;
				}
				else
				{
						if(top>=0)
						{
								current_node = stack[top--];
								count++;
								result[count] = current_node->val;
								current_node = current_node->right;
						}
						else
						{
								done = 1;    
						}
				}
		}
		count++;
		return result[B-1];
}


int main(int argc, char* argv)
{

		return 0;
}
