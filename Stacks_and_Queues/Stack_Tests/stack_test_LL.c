#include<stdio.h>
#include "stack_LL.h"

int main(){

	stack_node* head = NULL;

	push(&head,1);
	push(&head,2);
	push(&head,3);

	printf("popped from stack : %d \n",pop(&head));
	
	printf("peeked from stack : %d \n",peek(head));
	
	return 0;
}
