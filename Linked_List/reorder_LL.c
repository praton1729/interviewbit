#include<stdlib.h>

// Definition for singly-linked list.
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
 @input A : Head pointer of linked list 
 
 @Output head pointer of list.
*/
 
void reverselist(listnode* head){
    
    listnode* prev=NULL;
    listnode* current = head;
    listnode* next;
    
    while(next){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

listnode* reorderList(listnode* A) {
    
    if(A == NULL){ return NULL;}
    
    listnode* slow = A;
    listnode* fast = slow->next;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = (fast->next)->next;
    }
    
    listnode* head_1 = A;
    listnode* head_2 = slow->next;
    slow->next = NULL;
    
    // reverselist(head_2);
    
    listnode* prev=NULL;
    listnode* current = head_2;
    listnode* next = current;
    
    while(next){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head_2 = prev;
    
    A = listnode_new(0);
    
    current = A;
    
    while(head_1 || head_2){

        if(head_1){
            current->next = head_1;
            current = current->next;
            head_1 = head_1->next;
        }
        
        if(head_2){
            current->next = head_2;
            current = current->next;
            head_2 = head_2->next;
        }
    }
    
    A = A->next;
    
    return A;
    
}
