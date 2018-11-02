
/*=========================================

* File Name 	: max_depth_BT.c

* Purpose 		: A func() to find the max depth of a Binary tree

* Creation Date : 02-11-2018

* Last Modified : Friday 02 November 2018 01:49:01 PM IST

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
 * @Output Integer
 */

int maxDepth(treenode* A) {
    if(A==NULL) return 0;
    else
    {
        int ldepth = maxDepth(A->left);
        int rdepth = maxDepth(A->right);
        
        if(ldepth > rdepth) return (ldepth+1);
        else return (rdepth+1);
    }
    
}


int main(int argc, char* argv)
{

	return 0;
}
