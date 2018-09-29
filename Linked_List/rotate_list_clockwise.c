
/*=========================================

* File Name : rotate_list_clockwise.c

* Purpose 	: Rotate a linked list clockwise
			  by a given number of roations.

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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */

listnode* rotateRight(listnode* A, int B) {
    
    if(A == NULL) return NULL;
    if(B == 0) return A;
    
    listnode* current_node = A;
    int count = 1;
    
    while(current_node->next != NULL) current_node = current_node->next,count++;
    
    listnode* end_node = current_node;
    
    current_node = A;
    
    int right_rotations = B%count;
    
    int left_rotations = count - right_rotations;
    int i = 0;
    
    while(i < left_rotations-1){
        current_node = current_node->next;
        i++;
    }
    
    end_node->next = A;
    listnode* just_next_node = current_node->next;
    current_node->next = NULL;
    A = just_next_node;
    
    return A;
}

int main(int argc, char* argv)
{

	return 0;
}
