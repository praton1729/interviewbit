
/*=========================================

* File Name : min_stack.c

* Purpose 	: Creating a Min Stack which can 
			  yield the minimum in O(1) time

* Creation Date : 15-10-2018

* Last Modified : Monday 15 October 2018 07:08:10 PM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int top_index=-1;
int min_element=0;
static int stack[10000000];

void init() {
    top_index=-1;
    min_element=0;
}

void push(int x) {
    if(top_index < 0) stack[++top_index] = x, min_element=x;
    else if(x>=min_element){
        stack[++top_index] = x;
    }
    else{
        stack[++top_index] = 2*x - min_element;
        min_element = x;
    }
}

void pop() {
    if(top_index < 0) return;
    
    int temp = stack[top_index];
    top_index--;
    if(temp < min_element){
        min_element = 2*min_element - temp;
    }

}

int top() {
    if(top_index<0) return -1;
    else if(stack[top_index] < min_element) return min_element;
    else return stack[top_index];
}

int getMin() {
    if(top_index<0) return -1;
    else return min_element;
}

int main(int argc, char* argv)
{

	return 0;
}
