
typedef struct Stack_t
{
	int top;
	unsigned capacity;
	int* array;
}Stack;

Stack* Create_Stack(unsigned create_capacity){

	Stack* stack = (Stack*)malloc(sizeof(Stack));

	stack->capacity = create_capacity;
	stack->top = -1;
	stack->array = (int*)malloc(create_capacity*sizeof(int));

	return stack;	
} 

int is_full(Stack* stack)
{
	return (stack->top == stack->capacity - 1);
}

int is_empty(Stack* stack)
{
	return (stack->top == -1);
}

void push(Stack* stack, int data)
{
	if(is_full(stack))
	{
		return;
	}

	stack->array[++stack->top]=data;

	printf("%d pushed to stack\n", data);
}

int pop(Stack* stack)
{
	if(is_empty(stack))
	{
		return INT_MIN;
	}

	return stack->array[stack->top--];
}

int peek(Stack* stack)
{
	if(is_empty(stack))
	{
		return INT_MIN;
	}

	return stack->array[stack->top];
}
