#include<stdlib.h>

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


//@input A : Head pointer of linked list 
//@input B : Integer
//
//@Output head pointer of list.

listnode* partition(listnode* A, int B) {
    
    listnode* start_smaller = listnode_new(0);
    // listnode* end_smaller = listnode_new(0);
    
    listnode* temp = A;
    
    listnode* temp_smaller = NULL;
    listnode* new_smaller = NULL;
    
    while(temp!=NULL){
    
        if(temp->val < B){
            
            if(temp_smaller==NULL){
                // temp_smaller->val = temp->val;
                start_smaller = listnode_new(temp->val);
                temp_smaller = start_smaller;
            }
            else{
                new_smaller = listnode_new(temp->val);
                temp_smaller->next = new_smaller;
                temp_smaller = new_smaller;
            }
        }
        temp = temp->next;
    }
    
    listnode* end_smaller = temp_smaller;
    
    temp = A;
    
    while(temp!=NULL){
    
        if(temp->val >= B){
            
            if(temp_smaller==NULL){
                temp_smaller= listnode_new(temp->val);
                end_smaller = temp_smaller;
                start_smaller = temp_smaller;
            }
            else{
                new_smaller = listnode_new(temp->val);
                temp_smaller->next = new_smaller;
                temp_smaller = new_smaller;
            }
        }
        temp = temp->next;
    }
    
    return start_smaller;
    
}

