
/*=========================================

* File Name : reverse_between_given_indices.c

* Purpose :

* Creation Date : 29-09-2018

* Last Modified : Saturday 29 September 2018 07:03:21 PM IST

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
 * @input C : Integer
 * 
 * @Output head pointer of list.
 */

listnode* reverse(listnode* head){
    
    listnode* prev_node = NULL;
    listnode* current_node = head;
    listnode* next_node = NULL;
    
    while(current_node){
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    
    return prev_node;
}

listnode* reverseBetween(listnode* A, int B, int C) {
    
    if(A==NULL) return NULL;
    if(B==C) return A;
    
    listnode* current_node = A;
    listnode* node_B = NULL;
    listnode* node_just_before_B = NULL;
    listnode* node_C = NULL;
    listnode* node_just_after_C = NULL;
    int count = 1,len = 0;
    
    while(current_node!=NULL){
        if(count<B) node_just_before_B = current_node;
        if(count==B) node_B = current_node;
        if(count==C) node_C = current_node, node_just_after_C = current_node->next;
        current_node= current_node->next;
        count++;    
    }
    
    node_C->next = NULL;
    node_C = reverse(node_B);
    
    if(node_just_before_B){
        node_just_before_B->next = node_C;
    }
    else A = node_C;
    
    node_B->next = node_just_after_C;
    return A;
    
}

int main(int argc, char* argv)
{

	return 0;
}
