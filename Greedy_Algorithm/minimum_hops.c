
/*=========================================

* File Name : minimum_hops.c

* Purpose 	: A func() which outputs the min
			  no. of hops required to group the
			  people given the current seating
			  pattern.

* Creation Date : 23-10-2018

* Last Modified : Tuesday 23 October 2018 03:45:21 AM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int seats(char* A) {
    
    int MOD = 10000003;
    int result = 0, i, top = 0, len = strlen(A);
    
    int* stack = (int*) malloc(len*sizeof(int));
    
    for(i=0;i<len;i++){
        if(A[i]=='x') stack[top++] = i;
    }
    for(i=0;i<top;i++){
        printf("stack at %d is : %d\n",i,stack[i]);
    }
    top--;
    int median;
    int mid = top/2;
    top++;
    
    printf("top is : %d\n",top);
    
    if(top%2!=0) median = stack[mid];
    else median = (stack[mid] + stack[mid+1])/2;
    
    printf("median is : %d\n",median);
    
    for(i=0;i<top+1;i++){
        result += abs(stack[i]-median);
        printf("result is : %d\n",result);
    }
    
    return (result%MOD);
}


int main(int argc, char* argv)
{
	char* A = "....x..xx...x..";
	return 0;
}
