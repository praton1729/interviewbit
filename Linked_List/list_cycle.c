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
 * @Output head pointer of list.
 */
listnode* detectCycle(listnode* A) {
    
    listnode* slow = A;
    listnode* fast = A;
    
    while(slow && fast && fast->next){
        
        slow = slow->next;
        fast = (fast->next)->next;
        
        if(slow==fast){
            
            break;
        }
    }
    
    if(slow!=fast){
        return NULL;
    }
    
    listnode *temp = fast;
    fast = fast->next;
    int count = 1;
    while(fast!=temp)
    {
     fast = fast->next;
     ++count;
    }
    
    listnode *result = A;
    temp = A;
    
    while(count--){ temp = temp->next; }
    
    while(result!=temp){ result = result->next; temp = temp->next; }
    return result;
}

