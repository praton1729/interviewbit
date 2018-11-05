
/*=========================================

 * File Name		:	LCA.c

 * Purpose			:	A func() to find LCA of two integers
						in a given unordered BT.

 * Creation Date	:	05-11-2018

 * Last Modified	:	Mon 22 Dec 2008 10:36:49 PM PST

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
 * @input C : Integer
 * 
 * @Output Integer
 */

int find_node(treenode* A, int val)
{
		if(A==NULL) return 0;
		if((A->val == val) || find_node(A->left,val) || find_node(A->right,val)) return 1;
		else return 0;
}

treenode* find_LCA_util(treenode* root, int n1, int n2, int* v1, int* v2)
{
		if(root==NULL) return NULL;

		if(root->val == n1)
		{
				*v1 = 1;
				return root;
		}

		if(root->val == n2)
		{
				*v2 = 1;
				return root;
		}
		treenode* left_LCA  = find_LCA_util(root->left,n1,n2,v1,v2);
		treenode* right_LCA = find_LCA_util(root->right,n1,n2,v1,v2);

		if(left_LCA && right_LCA) return root;

		return (left_LCA!=NULL)?(left_LCA):(right_LCA);
}

int lca(treenode* A, int B, int C) {

		int exist_B = 0;
		int exist_C = 0;

		treenode* LCA = find_LCA_util(A,B,C,&exist_B,&exist_C);

		if((exist_B && exist_C) || (exist_B && find_node(LCA,C)) || (exist_C && find_node(LCA,B)))
		{
				return LCA->val;
		}
		//printf("exist_B is %d and exist_C is %d\n",exist_B,exist_C);
		else return -1;
}



int main(int argc, char* argv)
{

		return 0;
}
