
/*=========================================

* File Name : valid_BST.c

* Purpose 	: A func() which returns 1/0 if
			  the given tree is a valid BST 
			  or not.

* Creation Date : 25-10-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

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

int is_sub_tree_lesser(treenode* root, int data){
    if(root==NULL) return 1;
    
    if(root->val < data && is_sub_tree_lesser(root->left,data) 
    && is_sub_tree_lesser(root->right,data)){
        return 1;
    }
    else return 0;
}

int is_sub_tree_greater(treenode* root, int data){
    if(root==NULL) return 1;
    
    if(root->val > data && is_sub_tree_greater(root->left,data) 
    && is_sub_tree_greater(root->right,data)){
        return 1;
    }
    else return 0;
} 

int isValidBST(treenode* A) {

    if(A == NULL) return 1;
    
    if(is_sub_tree_lesser(A->left,A->val) && is_sub_tree_greater(A->right,A->val) 
        && isValidBST(A->left) && isValidBST(A->right)){
        return 1;
    }
    else return 0;
}


int main(int argc, char* argv)
{
	return 0;
}
