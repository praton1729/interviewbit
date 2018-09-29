
/*=========================================

* File Name : remove_duplicates_II.c

* Purpose 	: Delete all occurrences of 
			  duplicate elements in a LL

* Creation Date : 30-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>


//Definition for singly-linked list.

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
    listnode* node = (listnode *) malloc(sizeof(listnode));
    node->val = val;
    node->next = NULL;
    return node;
}

/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */

listnode* deleteDuplicates(listnode* A) {

		listnode* dummy = listnode_new(0);
		dummy->next = A;

		listnode* current_node = A;
		listnode* prev_node = dummy;

		while(current_node!=NULL){

				while( current_node->next!=NULL && (current_node->next->val == prev_node->next->val))
				{
						current_node = current_node->next;
				}

				if(prev_node->next == current_node) prev_node = prev_node->next;
				else prev_node->next = current_node->next;

				current_node = current_node->next;
		}

		return dummy->next;
}

int main(int argc, char* argv)
{

	return 0;
}
