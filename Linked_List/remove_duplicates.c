
/*=========================================

* File Name : remove_duplicates.c

* Purpose :

* Creation Date : 28-09-2018

* Last Modified : Friday 28 September 2018 03:53:30 PM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * Definition for singly-linked list.
 */ 

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

/*
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 *
 */

listnode* deleteDuplicates(listnode* A) {

		listnode* next_node = A->next;
		listnode* current_node = A;

		while(next_node != NULL){

				if(next_node->val == current_node->val){
						next_node = next_node->next;
				}
				else{
						current_node->next = next_node;
						current_node = next_node;
						next_node = next_node->next;
				}
		}
		current_node->next = NULL;
		return A;
}


int main(int argc, char* argv)
{

		return 0;
}
