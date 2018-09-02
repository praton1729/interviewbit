#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output Integer
 */
 typedef struct Stack 
 {
     int top;
     unsigned cap;
     int* array;
 }stack;
 
 stack* create_stack(unsigned cap){
     
    stack* new_stack = (stack*)malloc(sizeof(stack));
    if(!new_stack){
        return NULL;
    }
    
    new_stack->top = -1;
    new_stack->cap = cap;
    new_stack->array = (int*)malloc(cap * sizeof(int));
    
    if(!new_stack->array){
        return NULL;
    }
    return new_stack;
 }
 
 int isEmpty(stack* new_stack){
     return (new_stack->top==-1);
 }
 
 char peek(stack* new_stack){
     return new_stack->array[new_stack->top];
 }
 
 int pop(stack* new_stack){
     if(!isEmpty(new_stack)){
         return new_stack->array[new_stack->top--];
     }
     return -1;
 }
 
 void push(stack* new_stack, int op){
     new_stack->array[++new_stack->top] = op;
 }
int evalRPN(char** A, int n1) {
    
    stack* my_stack = create_stack(n1);
    int i = 0;
    
    if(!my_stack){
        return -1;
    }
    
    for(i=0;i<n1;i++){
        //printf("%s\n",A[i]);
        
        if(isdigit(A[i][0]) || isdigit(A[i][1])){
            push(my_stack,atoi(A[i]));
        }
        else{
            int val_1 = (int) pop(my_stack);
            int val_2 = (int) pop(my_stack);
            
            //printf("%d,%d\n",val_1,val_2);
            
            switch(**(A+i)){
                
                case '+':push(my_stack,val_2+val_1);break;
                case '-':push(my_stack,val_2-val_1);break;
                case '*':push(my_stack,val_2*val_1);break;
                case '/':push(my_stack,val_2/val_1);break;
            }
        }
    }
    return pop(my_stack);
}

