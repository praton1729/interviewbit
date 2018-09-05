
// Linked List implementation of stacks
#include<stdlib.h>
#include<limits.h>

typedef struct stack_node
{
	int data;
	struct stack_node* next;

}stack_node; 

stack_node* new_node(int new_data){

	stack_node* node = (stack_node*)malloc(sizeof(stack_node));

	node->data = new_data;
	node->next = NULL;

	return node;
}

int is_empty(stack_node* head){

	return !head;

}

void push(stack_node** head, int push_data){

	stack_node* node = new_node(push_data);

	node->next = *head;

	*head = node;

	printf("pushed to stack : %d \n",push_data);	

}

int pop(stack_node** head){

	if(is_empty(*head))
	{
		return INT_MIN;
	}

	stack_node* temp = *head;

	*head = (*head)->next;

	int popped = temp->data;

	free(temp);

	return popped;
}

int peek(stack_node* head){

	if(is_empty(head))
	{
		return INT_MIN;
	}

	return head->data;

}
