
/*=========================================

* File Name : merge_sorted_lists.c

* Purpose 	: Merge two sorted linked lists
			  and return the head of the list
			  in place without using extra memory.

* Creation Date : 28-09-2018

* Last Modified : Friday 28 September 2018 06:28:38 PM IST

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
 

/*
 * @input A : Head pointer of linked list 
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */

listnode* mergeTwoLists(listnode* A, listnode* B) {
    
    if(!A) return B;
    if(!B) return A;
    
    if(A->val < B->val){
        A->next = mergeTwoLists(A->next, B);
        return A;
    }
    else{
        B->next = mergeTwoLists(A, B->next);
        return B;
    }
}




int main(int argc, char* argv)
{

	return 0;
}
