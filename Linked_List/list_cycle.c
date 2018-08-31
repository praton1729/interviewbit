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
            
            return slow;
        }
    }
    
    return NULL;
}
