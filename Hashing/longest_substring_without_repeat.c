
/*=========================================

* File Name : longest_substring_without_repeat.c

* Purpose 	: A func() that returns maximum length
			  of substring from a given string which
			  has no repeated letters.

* Creation Date : 21-10-2018

* Last Modified : Sunday 21 October 2018 01:39:33 AM IST

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
#define MAX_CHARS 256

int lengthOfLongestSubstring(char* A) {

    int n = strlen(A);
    int current_len = 1;
    int max_len = 1; 
    int prev_index;
    int i;
    
    int* visited = (int*) malloc(MAX_CHARS*sizeof(int));
    
    for(i=0;i<MAX_CHARS;i++) visited[i] = -1;
    
    visited[A[0]]  = 0;
    
    for(i=1;i<n;i++){
        
        prev_index = visited[A[i]];
        
        if(prev_index==-1 || i - current_len > prev_index) current_len++;
        
        else{
            if(current_len>max_len) max_len = current_len;
            
            current_len = i - prev_index;
        }
        visited[A[i]] = i;
    }
    
    if(current_len > max_len) max_len = current_len;
    free(visited);
    return max_len;
}


int main(int argc, char* argv)
{
	char str[] = "tatti";
	printf("Output : %d\n",lengthOfLongestSubstring(str)); 
	return 0;
}
