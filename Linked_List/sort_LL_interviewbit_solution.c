
/*=========================================

* File Name : sort_LL_interviewbit_solution.c

* Purpose 	: Sort a LL inplace in O(nlogn) time
			  and constant additonal space.

* Creation Date : 01-10-2018

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

listnode* mergeTwoLists(listnode* A, listnode* B) {

		listnode *ans,*ptr1=A,*ptr2=B;
		if(A->val<B->val)
		{
				ans=A;
				ptr1=ptr1->next;
		}
		else
		{
				ans=B;
				ptr2=ptr2->next;
		}

		while(ptr1 && ptr2)
		{
				if(ptr1->val<ptr2->val)
				{
						ans->next=ptr1;
						ans=ptr1;
						ptr1=ptr1->next;
				}
				else
				{
						ans->next=ptr2;
						ans=ptr2;
						ptr2=ptr2->next;
				}
		}

		if(ptr2)
				ans->next=ptr2;
		else
				ans->next=ptr1;

		if(A->val<B->val)       return A;
		else                    return B;
}

void mergesort(listnode **A)
{
		listnode *start=*A,*slow=*A,*fast=*A,*prev=NULL;
		int len;
		len=0;
		while(fast && fast->next)
		{
				prev=slow;
				slow=slow->next;
				fast=fast->next->next;
				len=len+2;
		}
		if(fast)        len++;
		if(len<=1)      return;
		if(len>1)
		{

				prev->next=NULL;
				mergesort(&start);
				mergesort(&slow);
				*A=mergeTwoLists(start,slow); 
		}
}

listnode* sortList(listnode* A) {
		if(A==NULL || A->next==NULL)
				return A;
		mergesort(&A);
		return A;
}

int main(int argc, char* argv)
{

		return 0;
}
