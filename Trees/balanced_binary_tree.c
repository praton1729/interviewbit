
/*=========================================

* File Name		:	balanced_binary_tree.c

* Purpose		:

* Creation Date	:	02-11-2018

* Last Modified	:	Friday 02 November 2018 04:44:40 PM IST

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
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */

int max(int a, int b)
{
    return ((a)>(b)) ? (a):(b);    
}

int height(treenode* A)
{
    if(A==NULL) return 0;
    
    return 1+max(height(A->left),height(A->right));
}

int isBalanced(treenode* A) {
    
    if(A==NULL) return 1;
    
    int left_height = height(A->left);
    int right_height = height(A->right);
    int diff = abs(left_height - right_height);
    
    if(diff <= 1 && isBalanced(A->left) && isBalanced(A->right)) return 1;
    else return 0;
    
}

int main(int argc, char* argv)
{

	return 0;
}
