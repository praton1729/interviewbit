
/*=========================================

 * File Name : add_linked_lists.c

 * Purpose 	 : Adding two integers in the 
			   linked list format and returning
			   the result in a new linked list.

 * Creation Date : 29-09-2018

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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* addTwoNumbers(listnode* A, listnode* B) {

		listnode* dummy = listnode_new(0);

		listnode* start_node = dummy;
		listnode* node_A = A;
		listnode* node_B = B;

		int sum=0,carry=0;

		while(node_A || node_B){

				if(node_A!=NULL && node_B==NULL)
				{
						sum = node_A->val + carry;
						carry = sum/10;
						sum = sum%10;
						listnode* new_node = listnode_new(sum);
						dummy->next = new_node;
						dummy = dummy->next;
						node_A = node_A->next;
				}

				if(node_A==NULL && node_B!=NULL)
				{
						sum = node_B->val + carry;
						carry = sum/10;
						sum = sum%10;
						listnode* new_node = listnode_new(sum);
						dummy->next = new_node;
						dummy = dummy->next;
						node_B = node_B->next;
				}

				if(node_A!=NULL && node_B!=NULL)
				{
						sum = node_A->val + node_B->val + carry;
						carry = sum/10;
						sum = sum%10;
						listnode* new_node = listnode_new(sum);
						dummy->next = new_node;
						dummy = dummy->next;
						node_A = node_A->next;
						node_B = node_B->next;
				}
		}

		if(carry!=0) dummy->next = listnode_new(carry);
		return start_node->next;
}


int main(int argc, char* argv)
{

	return 0;
}
