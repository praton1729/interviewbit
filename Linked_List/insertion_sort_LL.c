
/*=========================================

* File Name : insertion_sort_LL.c

* Purpose 	: Sorting a LL using insertion
			  sort algorithm. This algorithm
			  requires extra space of O(n).

* Creation Date : 30-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>


/*Definition for singly-linked list.*/

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
 
void sorted_insert(listnode** head, listnode* new_node){
    
    listnode* current_node = NULL;
    
    if(*head == NULL || (*head)->val >= new_node->val){
        listnode* new_head_node = listnode_new(new_node->val);
        new_head_node->next = *head;
        *head = new_head_node;
    }
    else
    { 
        current_node = *head; 
        while (current_node->next!=NULL && current_node->next->val < new_node->val) 
        { 
            current_node = current_node->next; 
        } 
    listnode* new_val_node = listnode_new(new_node->val);
    new_val_node->next = current_node->next;
    current_node->next = new_val_node;
    }
}

listnode* insertionSortList(listnode* A) {
    
    listnode* result = NULL;
    
    listnode* current_node = A;
    listnode* next_node = NULL;
    
    while(current_node!=NULL){
        
        next_node = current_node->next;
        
        sorted_insert(&result, current_node);
        
        current_node = next_node;
    }
    
    return result;
}


int main(int argc, char* argv)
{

	return 0;
}
