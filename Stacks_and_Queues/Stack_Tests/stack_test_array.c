#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "stack_array.h"

int main(){

	Stack* stack = Create_Stack(100);

	push(stack,100);
	push(stack,200);
	push(stack,300);

	printf("popped from stack : %d \n",pop(stack));
	
	printf("peeked from stack : %d \n",peek(stack));
	
	return 0;
}
