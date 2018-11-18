
/*=========================================

* File Name		:	convert_sorted_list_to_BST.c

* Purpose		:	A func() that converts a sorted LL
					to a height balanced BST.

* Creation Date	:	18-11-2018

* Last Modified	:	Sunday 18 November 2018 02:55:16 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

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


// Definition for singly-linked list.

struct ListNode
{
		int val;
		struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val)
{
		listnode* node = (listnode *) malloc(sizeof(listnode));
		node->val = val;
		node->next = NULL;
		return node;
}


/**
 * @input A : Head pointer of linked list 
 * 
 * @Output root pointer of tree.
 */

int count_nodes(listnode* head)
{
		int count = 0;
		listnode* temp = head;

		while(temp!=NULL) 
		{
				temp = temp->next;
				count++;
		}
		return count;
}

treenode* sorted_list_to_BST(listnode** head, int n)
{
		if(n==0) return NULL;

		treenode* left_sub_tree = sorted_list_to_BST(head,n/2);

		treenode* root = treenode_new((*head)->val);

		root->left = left_sub_tree;

		(*head) = (*head)->next;

		root->right = sorted_list_to_BST(head,n - n/2 -1);

		return root;
}

treenode* sortedListToBST(listnode* A)
{
		int n = count_nodes(A);
		return sorted_list_to_BST(&A,n);
}


int main(int argc, char* argv)
{
		return 0;
}
