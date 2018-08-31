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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
listnode* removeNthFromEnd(listnode* A, int B) {
    
    int len = 0;
    
    listnode* temp = A;
    
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    //printf("%d",len);
    
    temp = A;
    int i = 0;
    
    if(len==0)
    {
        return NULL;
    }
    
    if(len==1 && B==1)
    {
        return NULL;
    }
    
    if(len < B)
    {
        temp = A->next;
        return temp;
    }
    else if(len > B)
    {
        for(i=1;i<len-B;i++)
        {
            temp = temp->next;        
        }
        
        temp->next = (temp->next)->next;
        return A;
    }
    else
    {
        return temp->next;
    }
    
    return temp;
}

