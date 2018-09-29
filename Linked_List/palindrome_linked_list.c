
/*=========================================

* File Name : palindrome_linked_list.c

* Purpose 	: checks if the passed linked list
			  is a palindrome or not. Returns
			  a 0 or 1 based on the check.

* Creation Date : 30-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output Integer
 */
 
int compare_lists(listnode* head_1, listnode* head_2){
    
    listnode* temp_1 = head_1;
    listnode* temp_2 = head_2;
    
    while(temp_1 && temp_2){
        if(temp_1->val == temp_2->val){
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }
        else return 0;
    }
    
    if(temp_1 == NULL && temp_2==NULL) return 1;
    else return 0;
}

void reverse(listnode** head){
    listnode* current_node = *head;
    listnode* prev_node = NULL;
    listnode* next_node = NULL;
    
    while(current_node!=NULL){
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    *head = prev_node;
}
int lPalin(listnode* A) {
    
    listnode *slow_ptr = A, *fast_ptr = A;
    listnode *second_half = NULL, *prev_slow_ptr = A;
    listnode* midnode = NULL;
    int result = 1;
    
    if(A != NULL && A->next != NULL){
        
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = (fast_ptr->next)->next;
            prev_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        
        if(fast_ptr != NULL){
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        
        second_half = slow_ptr;
        prev_slow_ptr->next = NULL;
        
        reverse(&second_half);
        
        result = compare_lists(A, second_half);
        
        reverse(&second_half);
        
        if(midnode!=NULL){
            prev_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else prev_slow_ptr->next = second_half;
    }
    return result;
}


int main(int argc, char* argv)
{

	return 0;
}
