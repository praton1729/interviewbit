
/*=========================================

* File Name		:	flatten_BT_linked_list.c

* Purpose		:

* Creation Date	:	05-11-2018

* Last Modified	:	Monday 05 November 2018 12:02:19 PM IST

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
 * @Output root pointer of tree.
 */

treenode* flatten(treenode* A) {
    
    if(A==NULL || (A->left==NULL && A->right==NULL)) return A;
    
    if(A->left!=NULL)
    {
        flatten(A->left);
        
        treenode* temp_right = A->right;
        A->right = A->left;
        A->left = NULL;
        
        treenode* temp = A->right;
        while(temp->right!=NULL) temp = temp->right;
        temp->right = temp_right;
    }
    flatten(A->right);
    return A;
}

int main(int argc, char* argv)
{

	return 0;
}
