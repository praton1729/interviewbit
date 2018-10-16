
/*=========================================

* File Name : largest_rectangle_histogram.c

* Purpose 	: Finding area of the largest rectangle
			  that can fit inside a given histogram.

* Creation Date : 16-10-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int largestRectangleArea(int* A, int n1) {

		int* stack = (int*) malloc(n1*sizeof(int));
		int top=-1,i=0;
		int area_with_top=0;
		int max_area=0;
		int top_element;

		while(i<n1){

				if(top==-1 || A[stack[top]] <= A[i]){
						stack[++top] = i;
						i++;
				}
				else{
						top_element = stack[top];
						top--;

						area_with_top = A[top_element]*((top==-1) ? (i):(i - stack[top] - 1));

						if(max_area < area_with_top) max_area = area_with_top;
				}
		}

		while(top != -1){
				top_element = stack[top];
				top--;

				area_with_top = A[top_element]*((top==-1) ? (i):(i - stack[top] - 1));

				if(max_area < area_with_top) max_area = area_with_top;
		}
		return max_area;
}


int main(int argc, char* argv)
{

		return 0;
}
