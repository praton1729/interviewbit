
/*=========================================

* File Name : valid_parentheses.c

* Purpose 	: Check for balancing parentheses.

* Creation Date : 01-10-2018

* Last Modified : Monday 01 October 2018 07:41:21 PM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
 
#define MAX_SIZE 1000

int isValid(char* A) {
    
    char* stack = (char*) malloc(MAX_SIZE*sizeof(char));
    int size = 0;
    int i = 0;
    for(i=0;i<strlen(A);i++){
        
        if(A[i]=='('||A[i]=='{'||A[i]=='['){
            stack[size++] = A[i];
            continue;
        }
        
        if(size==0) return 0;
        switch(A[i]){
            case ')':
                if(stack[size--]=='{' || stack[size--]=='[') return 0;
                else break;
            case '}':
                if(stack[size--]=='(' || stack[size--]=='[') return 0;
                else break;
            case ']':
                if(stack[size--]=='{' || stack[size--]=='(') return 0;
                else break;
                    
        }
    }
    
    return (size==0);
}


int main(int argc, char* argv)
{
	char* sample = "((((([{()}[]]{{{[]}}})))))";
	printf(" Output is : %d",isValid(sample));
	return 0;
}
