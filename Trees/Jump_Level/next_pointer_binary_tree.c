
/*=========================================

* File Name		:	next_pointer_binary_tree.c

* Purpose		:	A func() that connects adjacent 
					nodes in a tree.

* Creation Date	:	11-11-2018

* Last Modified	:	Sunday 11 November 2018 02:46:49 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>


//Definition for binary tree

struct TreeLinkNode
{
		int val;
		struct TreeLinkNode *left, *right, *next;
};

typedef struct TreeLinkNode treelinknode;


/*
 ** @input A : Root pointer of the tree 
 **
 ** @Output Void. Just modifies the args passed by reference 
 */

void connect(treelinknode* A) {

		if(A==NULL) return ;

		if(A->left) (A->left)->next = A->right;

		if(A->right) (A->right)->next = (A->next)?((A->next)->left):NULL;

		connect(A->left);
		connect(A->right);
		return ;
}


int main(int argc, char* argv)
{
		return 0;
}
